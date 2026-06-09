不知道为什么，这道题目被赋予了困难，但是正常遍历，效果也很好。。。
```
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
                return nums[i];
        }
        return nums[0];
    }
};
```
