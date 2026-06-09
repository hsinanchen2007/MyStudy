# 思路
先把数字转成字符串
然后用动态规划 
定义 dp[i]:前i个字符的翻译种数, nSize = 字符串长度
开辟长度为nSize加1的数组，

初始化: dp[0] = 1, dp[1] = 1;

递推过程: 对2<=i, i<=字符串长度, 迭代
1. 首先一定能取第i个数字 dp[i]=dp[i - 1]
2. 其次也许可以取第i-1和第i个数字 如果numstr[i - 2] == 1, 那么dp[i] += dp[i - 2]; 如果numstr[i - 2] == 2 且 numstr[i - 1]==0,1,2,3,4,5 那么dp[i] += dp[i - 2] 

得到结果: 最后返回dp[nSize]

# 代码
```
class Solution {
public:
    int translateNum(int num) {
        string numstr = to_string(num);
        int nSize = numstr.size();
        if (nSize == 1) return 1;
        else {
            vector<int> dp(nSize + 1, 0);
            dp[0] = dp[1] = 1;
            for (int i = 2; i <= nSize; ++i) {
                dp[i] = dp[i - 1];
                if (numstr[i - 2] == '1') {
                    dp[i] += dp[i - 2];
                }
                else if (numstr[i - 2] == '2') {
                    if ('0' <= numstr[i - 1] && numstr[i - 1] <= '5') {
                        dp[i] += dp[i - 2];
                    }
                }
            }
            return dp[nSize];
        }
    }
};
```