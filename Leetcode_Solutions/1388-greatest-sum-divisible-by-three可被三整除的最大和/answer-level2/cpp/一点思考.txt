### 解题思路
运用动态规划不用多说了。我这里只设了一个大小为3的数组存储模数余0，1，2的情况，要注意的是假如你一开始初始化dp数组都是0的话，由于余1和余2的和并不是0，你在更新数组的时候需要每次都判断当前的nums[i]的值加上对应dp[]的值是不是正确的余数。或者一开始把dp[2]和dp[1]都设置成无穷小，就不会有这个问题。另外更新dp数组时还要注意建立一个临时变量存储，不然会重复覆盖。

### 代码

```cpp
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int dp[3]={0,INT_MIN,INT_MIN};
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%3==0)
            {
                dp[0]+=nums[i];
                dp[1]+=nums[i];
                dp[2]+=nums[i];
            }
            else if(nums[i]%3==1)
            {
                int temp=dp[0];
                dp[0]=max(dp[0],dp[2]+nums[i]);
                dp[2]=max(dp[2],dp[1]+nums[i]);
                dp[1]=max(dp[1],temp+nums[i]);
            }
            else if(nums[i]%3==2)
            {
                int temp=dp[0];
                dp[0]=max(dp[0],dp[1]+nums[i]);
                dp[1]=max(dp[1],dp[2]+nums[i]);
                dp[2]=max(dp[2],temp+nums[i]);
            }
        }
        return dp[0];
    }
};
```