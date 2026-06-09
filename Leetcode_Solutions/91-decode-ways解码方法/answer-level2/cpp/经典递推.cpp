本题从题目上看挺像走楼梯那道经典题目的

设f(i)为前i个字符的解码方法数量。 显然最后两个字符有两种可能。
第一种， 最后一个字符单独编码， 如果可行， 则前面i-1个字符共有f(i-1)种可能编码， 如果不可行则为0
第二种， 最后两个

边界条件如下：
1. f(0) = 1
2. f(i) = valid(lastOneSymbol) \* f(i - 1) + valid(lastTwoSymbols) \* f(i - 2)

扫一遍递推即可。常数时间复杂度即可， 因为只需要记录前两个状态。 下面的代码使用数组递推则空间复杂度为O(N).

时间复杂度为O(N), 空间复杂度O(1).

```
class Solution {
public:
    int *dp;

    bool check(char h, char l){
        int hh = h - '0', ll = l - '0';
        int val = hh * 10 + ll;

        return val >= 10 && val <= 26;
    }

    int numDecodings(string s) {
        int n = s.length();
        dp = (int *)malloc((n + 1) * sizeof(int));

        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            dp[i] = 0;
            if(s[i - 1] > '0') dp[i] += dp[i - 1];
            if(i > 1 && check(s[i - 2], s[i - 1])) dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};
```

给出上面两个优化。

1. 如果字符串以0开头， 则直接返回0.
2. 若字符串任何地方有两个连续的0， 则返回0.


