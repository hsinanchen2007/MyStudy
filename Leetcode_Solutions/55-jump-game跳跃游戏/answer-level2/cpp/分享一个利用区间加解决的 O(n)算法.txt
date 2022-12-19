- 首先，如果从0位置出发，能到达 i 位置，那么  0 到 i 的 任一位置，从 0 出发都能到达。【这个条件很重要】
- 不妨设立dp数组，dp[i]代表，i 左边有多少个点能到达 i 位置。
题目中，nums[i]代表从 i 位置 出发，能直接到达 i + 1到i + nums[i] 的位置，显然，相当于dp[i + 1] 到 dp[i + nums[i]] 都要加 1，这是一个区间加的操作，这个操作能在O(1)的时间复杂度内完成。
只要令dp[i] + 1 , dp[i + nums[i] + 1] - 1，当所有的区间加操作完成后，从左往右累加dp[i],累加的值实时更新到dp[i],dp[i]就是所有在这个位置上有累加操作的和。
- 最后，根据最开始提出的必要条件，检查一遍dp数组，dp[1] 到 dp[n] 都不能为 0。
```
class Solution {
public:
 
    bool canJump(vector<int>& nums) {
       std::vector<int> dp(nums.size(), 0);
       for (int i = 0; i < nums.size(); ++i) {
           if (nums[i] > 0) {
               int st = i + 1;
               int ed = i + nums[i] + 1;
               if (st < nums.size()) dp[st] += 1;
               if (ed < nums.size()) dp[ed] -= 1;
           }
       }
       for (int i = 1; i < nums.size(); ++i) {
           dp[i] += dp[i - 1];
           if (dp[i] == 0) {
               return false;
           }
       }
       return true;
    }
};
```

 