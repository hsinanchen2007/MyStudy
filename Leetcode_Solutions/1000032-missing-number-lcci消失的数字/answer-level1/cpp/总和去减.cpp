```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(i+1);
            sum-=nums[i];
        }
        return sum;
    }
};
```
解题思路：先求从1到n的总和，减去nums剩下的就是缺失的数字，同268.缺失的数字一个思路