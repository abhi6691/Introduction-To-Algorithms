/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description:
***********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

typedef vector <int> vi;

template <typename T>
void swap(T *a, T *b) { T t = *a; *a = *b; *b = t;}

void printVec(vi v, int l, int r){for(int i = l; i <= r; i++) cout<<v[i]<<" "; cout<<endl;}
void printVec(vi v){ printVec(v, 0, v.size() - 1);}

void merge(vi &A, int l, int m, int r) // 0 0 1
{
	//printf("merge interval: left: %d mid: %d right: %d\n", l, m, r);
	vi L, R;
	int i;
	for (i = l; i <= m; i++)
		L.push_back(A[i]);
	for (; i <=r; i++)
		R.push_back(A[i]);

	//printf("Left Array:"); printVec(L);
	//printf("Right Array:"); printVec(R);

	int li = 0, ri = 0;
	i = l;

	while (li < L.size() && ri < R.size())
	{
		if (L[li] <= R[ri])
		{
			A[i] = L[li];
			li++;
		}
		else
		{
			A[i] = R[ri];
			ri++;
		}

		i++;
	}

	//printf("Done with while loop\n");

	while (ri < R.size())
	{
		A[i] = R[ri];
		ri++; i++;
	}

	while (li < L.size())
	{
		A[i] = L[li];
		li++; i++;
	}

	//printf("Done with if checks\n");
}

void mergesort(vi &A, int l, int r) // 0-1
{
	if (l < r)
	{
		//printf("mergesort left: %d, right: %d\n", l, r);
		int m = l + ((r-l)>>1); // 0
		mergesort(A, l, m);
		mergesort(A, m+1, r);
		merge(A, l, m, r);
	}
}

int main()
{
	freopen("/Users/Abhi/Desktop/Job/inputf.in", "r", stdin);
	freopen("/Users/Abhi/Desktop/Job/outputf.in", "w", stdout);

	int n; cin>>n;
	vi v;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin>>t;
		v.push_back(t);
	}

	mergesort(v, 0, n-1);
	printVec(v);

	return 0;
}