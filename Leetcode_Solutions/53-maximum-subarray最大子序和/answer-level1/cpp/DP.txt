# **动态规划:**
上代码：
```C++ []
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum=0;
        for(int i = 0; i < nums.size();i++){
            if(sum>0)
            {
                sum +=nums[i];
            }
            else{
                sum = nums[i];
            }
            ans=max(sum,ans);
        }
        return ans;
    }
};
遍历数组的每一个元素，遍历过程中对于当前元素来说，
sum表示该元素之前所有能够与该元素构成连续数列的子数列中和最大的那一个，
ans表示以该元素结尾的连续数列中和最大的那一个。
```
