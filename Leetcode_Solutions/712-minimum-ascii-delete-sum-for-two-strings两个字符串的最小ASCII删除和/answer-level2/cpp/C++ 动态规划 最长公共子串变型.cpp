## 思路
1. 处理之前，两个字符串的ASCII值综合sum是固定的
2. 处理之后，两个字符串是相同的，即处理后的字符串是原来两个字符串的公共子串
3. sum = s1的ASCII值和 + s2的ASCII值和 = 2 * 公共子串的ASCII值和 + 要删除的ASCII值和
4. 如果要将"要删除的ASCII值和"最小化，即要求解"公共子串的ASCII值和"最大值
5. 相比于原始的最长公共子串题目，这里需要变化的是将dp值的变化从1改成对应的ASCII码值

## 附
[最长公共子串题解](https://leetcode-cn.com/problems/longest-common-subsequence/solution/c-dong-tai-gui-hua-zhuang-tai-ya-suo-you-hua-si-lu/)

## 本体代码
时间复杂度 O(MN)
空间复杂度 O(N)
```cpp
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sum = 0;
        for (const auto c : s1)
            sum += c;
        for (const auto c : s2)
            sum += c;

        const int size = s2.size();
        vector<int> dp(size, 0);

        for (const auto c : s1) {
            int last = dp[0];
            if (c == s2[0]) {
                dp[0] = c;
            }
            for (int i = 1; i < size; i++) {
                int backup = last;
                last = dp[i];
                if (c == s2[i]) {
                    dp[i] = backup + c;
                } else if (dp[i - 1] > dp[i]) {                    
                    dp[i] = dp[i - 1];
                }
            }
        }
        return sum - 2 * dp[size - 1];
    }
};
```