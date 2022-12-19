#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>>str;
		int a = nums.size();
		int b, c, d;
		int temp;
		for (int i = 0; i < a; i++) {
			temp = target - nums[i];
			for (int j = i + 1; j < a; j++) {
				b = nums[j];
				c = j + 1;
				d = a - 1;
				while (c < d) {
					int sum = b + nums[c] + nums[d];
					if (sum == temp) {
						str.push_back({ nums[i],b,nums[c],nums[d] });
						c++;
						d--;
					}
					if (sum < temp) {
						c++;
					}
					if (sum >temp) {
						d--;
					}

				}
			}
		}
		sort(str.begin(), str.end());
		str.erase(unique(str.begin(), str.end()), str.end());
		return str;
	}
};