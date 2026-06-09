### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        vector<int>memo(nums.size());
        memo[0]=nums[0];
        int Max = nums[0];
        for(int i=1;i<nums.size();i++){
            memo[i]=max(nums[i]+memo[i-1],nums[i]);
            Max = max(Max, memo[i]);
        }
    return Max;
    }

};
```