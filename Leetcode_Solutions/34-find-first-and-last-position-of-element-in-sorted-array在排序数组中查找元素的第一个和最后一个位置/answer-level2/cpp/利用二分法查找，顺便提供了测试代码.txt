/*
思路：其实跟快排很像，二分法递归查找
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> out(2,-1);
		search(nums, target, out,0,nums.size()-1);
		return out;
	}

	void search(vector<int>&nums, int target, vector<int>& out, int left, int right) {
		int mid = (right + left) / 2;
		if (left > right)
			return;
		if (nums[mid]==target)
		{
			if (out[0] == -1)
				out[0] = mid;
			if (mid < out[0])
				out[0] = mid;
			if (mid > out[1])
				out[1] = mid;
		}
		if (left == right)
			return;
		search(nums, target, out, left, mid-1);
		search(nums, target, out, mid+1, right);
		return;
	}
};

int main() {
	vector<int> in{ 5,7,7,8,8,9 };
	int target = 7;
	Solution s;
	vector<int> a;
	a=s.searchRange(in, target);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}
