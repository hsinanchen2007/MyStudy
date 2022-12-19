### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>0)
                nums[i]=nums[i]+nums[i-1];
            if(max<nums[i])max=nums[i];
        }
        return max;
    }
};
```