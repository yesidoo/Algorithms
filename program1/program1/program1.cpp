// program1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void find_max_crossing_subarray(float *A, int low, int high, int mid, float *R)
{
	float sum_left = 0;
	float max_sum_left = -10000;
	int left_low = 0;
	for (int i = mid; i >= low; --i)
	{
		sum_left += A[i];
		if (sum_left > max_sum_left)
		{
			max_sum_left = sum_left;
			left_low = i;
		}
	}
	float sum_right = 0;
	float max_sum_right = -10000;
	int right_high = high;
	for (int i = mid+1; i <= high; ++i)
	{
		sum_right += A[i];
		if (sum_right > max_sum_right)
		{
			max_sum_right = sum_right;
			right_high = i;
		}
	}
	R[0] = left_low;
	R[1] = right_high;
	R[2] = max_sum_left + max_sum_right;
}

void find_max_subarray(float *A, int low, int high, float *R)
{
	if (low == high)
	{
		R[0] = low;
		R[1] = high;
		R[2] = A[low];
		return;
	}
	int mid = (low + high) / 2;
	float left_R[3];
	float right_R[3];
	float cross_R[3];
	find_max_subarray(A, low, mid, left_R);
	find_max_subarray(A, mid+1, high, right_R);
	find_max_crossing_subarray(A, low, high, mid, cross_R);
	if (left_R[2] >= right_R[2] && left_R[2] >= cross_R[2])
	{
		R[0] = left_R[0];
		R[1] = left_R[1];
		R[2] = left_R[2];
	}
	else if (left_R[2] <= right_R[2] && right_R[2] >= cross_R[2])
	{
		R[0] = right_R[0];
		R[1] = right_R[1];
		R[2] = right_R[2];
	}
	else
	{
		R[0] = cross_R[0];
		R[1] = cross_R[1];
		R[2] = cross_R[2];
	}
}

int main()
{
	float A[16] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	float R[3];
	find_max_subarray(A, 0, 15, R);
	cout << R[0] << "," << R[1] << "," << R[2] << endl;
    return 0;
}

