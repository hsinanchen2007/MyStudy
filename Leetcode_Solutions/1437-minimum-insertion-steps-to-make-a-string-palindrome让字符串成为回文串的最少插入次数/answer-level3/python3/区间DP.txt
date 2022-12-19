一个典型的区间DP问题，通用做法是首先把区间开闭想明白，本题使用了[left,right]即闭区间，先遍历区间长度，再遍历左端点，注意区间长度至少从1开始遍历，左端点最远遍历到(区间最大长度-左端点下标)，防止右端点超限，初始化为按照起点下标初始化二维数组，第一维表示所有可能的左端点下标，第二维表示所有可能的右端点下标，区间DP属于一层一层DP，某一层只会用到上一层长度的值，每个状态只会被计算一次，因此无需记忆化，返回0到长度-1的值即可
```
class Solution:
    def minInsertions(self, s: str) -> int:
        dp = [[0 for _ in range(len(s)) ] for _ in range(len(s))]
        for l in range(2,len(s)+1):#区间dp注意从长度至少从1开始枚举，否则会超出list范围，看初始化情况可以选择大于1的枚举点
            for left in range(len(s)-l+1):#注意右边界范围
                right = left + l -1
                if s[right] == s[left]:
                    dp[left][right] = dp[left+1][right-1]
                else:
                    dp[left][right] = dp[left+1][right] + 1
                    dp[left][right] = min(dp[left][right],dp[left][right-1] + 1)
        return dp[0][len(s)-1]
```
说下思路：回文字符串的最少次数一定是只在一边加字母，如果你同时在两端加字母，那么一定可以去掉还是回文，所以不考虑这种情况，dp的状态计算要记住考虑最后一步，如果两边字母相等那么只需要把中间变成回文就好，假设最后一步加在了左边，那么右端使用原字母，那么去掉左和右边的字母，还是回文，而由于只有右端使用了原字母，相当于把[left,right-1]变成回文，否则反之，最后列出来就是转移公式