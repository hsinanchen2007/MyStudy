```
class Solution {
public:
	static bool cmp(const int&a, const int &b)
	{
		return a<b;
	}
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end(), cmp);
		int ans = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size() - 2; i++) {
            int start = i+1, end = nums.size() - 1;
			while (start < end) {
				int sum = nums[i] + nums[start] + nums[end];
				if (abs(sum - target)< abs(ans - target)) {
					ans = sum;
				}
				if (sum < target) {
					start += 1;
				}
				else if (sum > target) {
					end -= 1;
				}
				else if (sum == target) {
					return sum;
				}
			}

		}
		return ans;
	}
};
```
