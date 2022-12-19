![_{RB6@BZKS\[2C3CA{7(SPIU.png](https://pic.leetcode-cn.com/f09e835b1e3b5b51cd036c5d9d53f8088260670db627f540283c74171f814da5-_%7BRB6@BZKS%5B2C3CA%7B7\(SPIU.png)

首先理清思路，输入为非负数，能让我们跳不到终点的因素**只有0**，
套用dong哥[@labuladong](/u/labuladong/)的思路，动态规划实质就是穷举所有的可能性。由此引出**状态**和**选择**：
状态，即我们要遍历给定数据的每一个位置；选择，即每一个位置可能出现的情况。
**针对本题：**
状态：数组下标i，即当前所处位置
选择：当前位置 跳的距离是不是0，即nums[i]

走一下动态规划的套路：
**状态：** dp[i] 表示目前位置为止我们能跳的最远距离
**状态转移：** if(nums[i]!=0) dp[i]=max(dp[i-1],i+nums[i]);   //i+nums[i] 即位置i上，从0算起能跳的最远距离
           if(nums[i]==0)  dp[i]=dp[i-1]>i? dp[i-1]:0;   //如果dp[i-1] 最多只能跳到位置i，i只能跳0，那么一定到不了终点
**初始状态：** dp[0]=nums[0];

# 动态规划

```
bool canJump(vector<int>& nums) {
        int len=nums.size();
        if (len<=1 ) return true;
        if(nums[0]==0) return false;
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        for(int i=1;i<nums.size()-1;i++){ //只需要计算到倒数第二个位置即可
            if(nums[i]==0)
                dp[i]=dp[i-1]>i?dp[i-1]:0;
            else dp[i]=max(dp[i-1],i+nums[i]);
            if(dp[i]>=nums.size()-1) return true;//剪枝，提前满足跳跃距离则返回true
            if(dp[i]==0) return false;
        }
        return dp[nums.size()-2]==0?false:true;
    }
```
申请了额外dp数组，空间复杂度O（n）；遍历一趟，时间复杂度O（n）

# 空间优化
注意到我们每次只需要保存i位置的最大跳跃距离，其他位置的跳跃距离我们并不关心，因此可以只用一个变量代替dp数组
```
 bool canJump(vector<int>& nums) {
        int len=nums.size();
        if (len<=1 ) return true;
        if(nums[0]==0) return false;
        int dp=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==0) dp=dp>i?dp:0;
            else dp=max(dp,i+nums[i]);
            if(dp>=nums.size()-1) return true; //剪枝
            if(dp==0) return false;
        }
        return true;
    }
```
空间复杂度O（1），时间复杂度O（n）

