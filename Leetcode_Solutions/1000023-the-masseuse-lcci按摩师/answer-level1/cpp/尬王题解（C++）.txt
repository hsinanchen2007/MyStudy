### 解题思路
![image.png](https://pic.leetcode-cn.com/2c8ffa1403b57c666a6585471c248cf28d9e55aa332cd6115b76c9e524c12bba-image.png)
每次只需要判断当前数据之前的（不包括前一个）所有数据最大值即可，更新当前数据的值即可，利用max保存过程中的最大值，返回就是所求。
### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        
        if(nums.size()==0){return 0;}
        if(nums.size()==1){return nums[0];}
        if(nums.size()==2){return nums[0]>nums[1]?nums[0]:nums[1];}
        int dp[nums.size()];
        dp[0] = nums[0];dp[1] = nums[1];
        int max = dp[0]>dp[1]?dp[0]:dp[1];int ma;
        for(int i = 2;i<nums.size();i++)
        {
            ma = -1;
            for(int j = 0;j<i-1;j++)
            {
                if(dp[j]>ma){ma = dp[j];}
            }
            dp[i] = nums[i]+ma;
            if(dp[i]>max){max = dp[i];}
        }
        return max;
    }
};
```