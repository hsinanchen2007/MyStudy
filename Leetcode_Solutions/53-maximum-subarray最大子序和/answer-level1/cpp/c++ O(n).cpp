### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int maxsum = nums[0],i,len = nums.size();
     for(i = 1;i<len;i++)
     {
         nums[i] = max(nums[i-1]+nums[i],nums[i]);
         if(maxsum<nums[i])
         maxsum = nums[i];
     }
     return maxsum;
    }
};
```