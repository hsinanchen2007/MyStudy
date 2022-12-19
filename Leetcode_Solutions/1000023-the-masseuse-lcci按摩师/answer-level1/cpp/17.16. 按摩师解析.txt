### 解题思路
这题是一道比较简单的动态规划题目：
只要记住一点：最优解就是不相连的数据加起来值最大，所以有如下情况：
当遍历到nums[i]的时候，
   如果最大累加值算上nums[i]就有，dp[i] 就等于 nums[i]的上上个累加值dp[i-2] 加上 nums[i],及 dp[i] = dp[i-2] + nums[i];
   如果最大累加值不算上这个nums[i]的话，那么 dp[i] 就跟dp[i-1]相等了对吧，因为相邻不能相加嘛；
   综合以上两种情况，dp[i]选取两种情况的最大值，关键的动态方程为：
        dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
  
 剩下的就是边界问题，直接提前赋值即可，代码如下：
### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {

        int len = nums.size();
        vector<int> dp(len,0);
        if(nums.size() == 0){// 长度为0 返回0
            return 0;
        }
        if(nums.size()==1){//长度为1，因为就一个数，返回nums[0];
            return nums[0];
        }

        if(nums.size() == 2){//长度为2，因为有两个数字，所以返回两者最大值，为嘛要单独算nums.size()==2，因为下面循环i是从2开始的，所以dp[i-2]的i-2不能为负数；
            return max(nums[0],nums[1]);
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i<len;i++){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }

        return dp[len-1];//返回遍历到最后一个nums[i]的时候的dp 为最大值；
    }
};
```