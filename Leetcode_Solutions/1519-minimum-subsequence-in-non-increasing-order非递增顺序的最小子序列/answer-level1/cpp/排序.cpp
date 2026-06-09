降序排列，找到前缀和大于剩余和的第一个位置

```cpp
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int i, sum = 0, s = 0;
        for(i = 0; i < nums.size(); ++i)
        	sum += nums[i];
        for(i = 0; i < nums.size(); ++i)
        {
        	if(nums[i] + s > sum - nums[i])
        		break;
        	else
        	{
        		s += nums[i];
        		sum -= nums[i];
        	}
        }
        return vector<int>(nums.begin(),nums.begin()+i+1);
    }
};
```