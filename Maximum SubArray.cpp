/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: Find subarray with the maximum sum
***********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

typedef vector <int> vi;

template <typename T>
void swap(T *a, T *b) { T t = *a; *a = *b; *b = t;}

void printVec(vi v, int l, int r){for(int i = l; i <= r; i++) cout<<v[i]<<" "; cout<<endl;}
void printVec(vi v){ printVec(v, 0, v.size() - 1);}

struct subArr
{
	int l;
	int r;
	int sum;
};

subArr findMaxCrossingSubArr(vi A, int l, int m, int r)
{
	int maxSumLeft = INT_MIN, currSum = 0;
	int li = m;

	for (int i = m; i >= l; i--)
	{
		currSum += A[i];
		if (currSum > maxSumLeft)
		{
			maxSumLeft = currSum;
			li = i;
		}
	}

	int maxSumRight = INT_MIN; currSum = 0;
	int ri = m+1;

	for (int i = m+1; i <= r; i++)
	{
		currSum += A[i];
		if (currSum > maxSumRight)
		{
			maxSumRight = currSum;
			ri = i;
		}
	}

	subArr ans;
	ans.l = li; ans.r = ri; ans.sum = maxSumLeft + maxSumRight;

	return ans;
}

subArr findMaxSubArr(vi A, int l, int r)
{
	subArr ans;
	if (l == r)
	{
		ans.l = ans.r = l;
		ans.sum = A[l];
		return ans;
	}

	//printf("Searching for max subarray in range: %d to %d\n", l, r);

	int m = l + ((r-l)>>1);
	subArr lSub = findMaxSubArr(A, l, m);
	subArr rSub = findMaxSubArr(A, m+1, r);
	subArr cSub = findMaxCrossingSubArr(A, l, m, r);

	//printf("left subarray found from %d to %d with sum %d\n", lSub.l, lSub.r, lSub.sum);
	//printf("right subarray found from %d to %d with sum %d\n", rSub.l, rSub.r, rSub.sum);
	//printf("cross subarray found from %d to %d with sum %d\n", cSub.l, cSub.r, cSub.sum);

	if (lSub.sum >= rSub.sum && lSub.sum >= cSub.sum) ans = lSub;
	else if (rSub.sum > lSub.sum && rSub.sum >= cSub.sum) ans = rSub;
	else ans = cSub;

	//printf("Returning subarray %d to %d with sum %d\n", ans.l, ans.r, ans.sum);

	return ans;
}

int main()
{
	freopen("/Users/Abhi/Desktop/Job/inputf.in", "r", stdin);
	freopen("/Users/Abhi/Desktop/Job/outputf.in", "w", stdout);

	int n, t; vi v;
	cin>>n;

	for (int i = 0; i < n; i++)
	{
		cin>>t;
		v.push_back(t);
	}

	subArr ans = findMaxSubArr(v, 0, n-1);
	printf("Maximum sum subarray found from index %d to %d, sum: %d", ans.l, ans.r, ans.sum);

	return 0;
}