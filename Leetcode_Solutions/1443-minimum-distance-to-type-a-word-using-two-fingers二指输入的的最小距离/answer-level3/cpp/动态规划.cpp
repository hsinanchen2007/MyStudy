执行结果：通过
显示详情
执行用时 : 324 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :200.3 MB, 在所有 C++ 提交中击败了100.00%的用户


```C++ []
class Solution {
public:
    int minimumDistance(string word, int pos = 0, char left = 26, char right = 26) {
        if (pos < word.length()) {
            if (dp[left][right][pos] == 0) {
                char to = word[pos] - 'A';
                dp[left][right][pos] = min(cost(left, to) + minimumDistance(word, pos + 1, to, right),  
                                           cost(right, to) + minimumDistance(word, pos + 1, left, to));
            }
        }
        return dp[left][right][pos];
    }

private:
    int dp[27][27][301] = {};
    int cost(char from, char to) {
        if (from == 26) return 0;
        return abs(from/6 - to/6) + abs(from%6 - to%6);
    }
};
```

