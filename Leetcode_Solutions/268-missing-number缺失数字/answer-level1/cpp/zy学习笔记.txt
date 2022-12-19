- ### 解题思路
小白暴力比较

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums[nums.size()-1];
        int i=0;
        for(;i<nums.size();i++)
        {
            if(nums[i]!=i)    //i相当于到n的序列
            break;
        }
        return i;
    }
};
```