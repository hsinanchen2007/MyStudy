先排序，最大积只会是最大三个正数积或者最小两个负数和一个最大正数的积
```
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
		int res=0;
		if (n == 3) return nums[0] * nums[1] * nums[2];
		sort(nums.begin(), nums.end());		
		res = max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
		return res;
    }
};
```
