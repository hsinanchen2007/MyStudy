仿照元仲辛的解法，实现了C++版本

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        //vector<vector<int>> len(size,vector<int>(size));
        int len[size][size] = {0};
        for (int i = size - 1; i >= 0; i--) {
            len[i][i] = 1;
            for (int j = i + 1; j < size; j++) {
                if (s[i] == s[j]) {
                    len[i][j] = len[i + 1][j - 1] + 2;
                } else {
                    len[i][j] = max(len[i + 1][j], len[i][j - 1]);
                }
            }
        }
        return len[0][size - 1];
    }
};
```

遇到的语言基本的两个问题：

1、多维数组要显示初始化，不初始化导致程序错乱
2、使用多维数组，要比vector性能优化4倍