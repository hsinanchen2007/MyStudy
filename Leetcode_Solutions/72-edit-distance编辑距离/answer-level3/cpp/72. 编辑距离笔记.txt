### 解题思路
1. 动态规划解法，[参考链接](https://leetcode-cn.com/problems/edit-distance/solution/zi-di-xiang-shang-he-zi-ding-xiang-xia-by-powcai-3/)

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        if (m * n == 0) return m + n;

        int dis[m + 1][n + 1];

        //初始化边界
        for (int i = 0; i < m + 1; i++) {
            dis[i][0] = i;
        }

        for (int i = 0; i < n + 1; i++) {
            dis[0][i] = i;
        }

        // 填充dis
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                int left = dis[i - 1][j] + 1;
                int up = dis[i][j - 1] + 1;
                int left_up = dis[i - 1][j -1];
                if (word1[i - 1] != word2[j - 1]) left_up++;
                dis[i][j] = min(min(left, up), left_up);
            }
        }

        return dis[m][n];
    }
};
```