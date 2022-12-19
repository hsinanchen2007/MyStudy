### 状态转移方程
```cpp
f(i, j) 代表 text1[0...i] 和 text2[0...j] 的最长公共子串长度
f(i, j) = f(i-1, j-1) + 1,              text1[i] == text2[j]
f(i, j) = max(f(i-1, j), f(i, j-1)),    text1[i] != text2[j]
```


### 递归+备忘录（每求得一个 dp 就存进备忘录，注意备忘录访问不要越界！）
```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty()) return 0;
        vector<vector<int>> table(text1.size(), vector<int>(text2.size(), -1));
        return dp(text1, text2, text1.size() - 1, text2.size() - 1, table);
    }
    
    int dp(const string &text1, const string &text2, int i, int j, vector<vector<int>> &table) {
        if (i == -1 || j == -1) return 0;
        if (table[i][j] != -1) return table[i][j];
        if (text1[i] == text2[j]) {
            int leftup = dp(text1, text2, i-1, j-1, table);
            if (i >= 1 && j >= 1) table[i-1][j-1] = leftup; // memo！
            table[i][j] = 1 + leftup;                       // memo
            return table[i][j];
        }
        int text1sub = dp(text1, text2, i-1, j, table);
        if (i >= 1) table[i-1][j] = text1sub;               // memo！
        int text2sub = dp(text1, text2, i, j-1, table);
        if (j >= 1) table[i][j-1] = text2sub;               // memo！
        table[i][j] = max(text1sub, text2sub);              // memo
        return table[i][j];
    }
};
```

### 迭代
```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty()) return 0;
        vector<vector<int>> table(text1.size(), vector<int>(text2.size(), 0));
        
        table[0][0] = text1[0] == text2[0] ? 1 : 0;
        
        for (int j = 1; j < text2.size(); j++) {
            table[0][j] = text1[0] == text2[j] ? 1 : table[0][j-1];
        }
        
        for (int i = 1; i < text1.size(); i++) {
            table[i][0] = text1[i] == text2[0] ? 1 : table[i-1][0];
        }
        
        for (int i = 1; i < text1.size(); i++) {
            for (int j = 1; j < text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    table[i][j] = table[i-1][j-1] + 1;
                } else {
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }
        return table.back().back();
    }    
};
```