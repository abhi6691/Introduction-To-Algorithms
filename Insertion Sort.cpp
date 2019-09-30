/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: Insertion Sort
***********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

typedef vector <int> vi;

template <typename T>
void swap(T *a, T *b) { T t = *a; *a = *b; *b = t;}

void printVec(vi v){for(int i = 0; i < v.size(); i++) cout<<v[i]<<" "; cout<<endl;}

void InsertionSort(vi &v)
{
	int n = v.size();

	for (int i = 1; i < n; i++)
	{
		int key = v[i], j = i-1;
		while (j >= 0 && v[j] > key)
		{
			v[j+1] = v[j];
			j--;
		}

		v[j+1] = key;
	}
}

int main()
{
	freopen("/Users/Abhi/Desktop/Job/inputf.in", "r", stdin);
	freopen("/Users/Abhi/Desktop/Job/outputf.in", "w", stdout);

	int n;
	vi v;

	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin>>t;
		v.push_back(t);
	}

	InsertionSort(v);
	printVec(v);

	return 0;
}