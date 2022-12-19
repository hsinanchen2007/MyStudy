### 解题思路
动态规划，找出其中规则，并定义longlong类型的dp二维数组。
dp[i][j] 表示由i个字符组成的，结尾是j的字符串的存在的个数。
那么根据题干的要求，我们可以看到针对这些字符串有一定的要求，则：
我们定义j 0-4 分别是对应字符'a'、'e'、'i'、'o'、'u';
再看题意，合法的组合为：
ae、ea、ei、ia、ie、io、iu、oi、ou、ua
则就可以根据对应关系，推出DP关系；
再进行初始化操作，进行动态规划得出结果。
### 代码

```cpp
class Solution {
public:
    int countVowelPermutation(int n) {
        if (n == 0) {
            return 0;
        }
        vector<vector<long long>> dp(n + 1, vector<long long>(5,0));
        vector<long long> vec(5,0);
        vector<long long> vec1(5,1);
        dp[0] = vec;
        dp[1] = vec1;
        long long m = pow(10, 9) + 7;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 5; j++) {
                dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % m;
                dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % m;
                dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % m;
                dp[i][3] = (dp[i - 1][2]) % m;
                dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % m;
            }
        }
        long long count = 0;
        for (int i = 0; i < 5; i++) {
            count += dp[n][i];
        }
        return count % m;
    }

};
```