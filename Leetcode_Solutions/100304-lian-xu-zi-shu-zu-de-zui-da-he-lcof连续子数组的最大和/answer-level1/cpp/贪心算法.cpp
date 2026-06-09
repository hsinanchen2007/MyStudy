### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int maxx = nums[0], dp = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (dp < 0)dp = nums[i];
			else dp += nums[i];
			maxx = max(dp, maxx);
		}
		return maxx;
    }
};
```