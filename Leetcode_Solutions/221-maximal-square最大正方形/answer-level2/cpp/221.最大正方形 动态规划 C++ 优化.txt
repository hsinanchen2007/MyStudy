### 解题思路
![image.png](https://pic.leetcode-cn.com/dedfae0e4b121e1f9320b4bfa68d09b0ee0c32f7c0bab44bde5621e205fa0e88-image.png)

内存优化，使用两个vector<int>替换m x n的vector<vector<int>>
### 代码

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> t1(n, 0);
        vector<int> t2(n, 0);
        int max_length = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != '1') continue;
                if (i * j == 0) {
                    t1[j] = 1;
                    max_length = max(max_length, t1[j]);
                    continue;
                }
                int min_length = min(t2[j-1], t2[j]);
                min_length = min(min_length, t1[j-1]);
                t1[j] = min_length + 1;
                max_length = max(max_length, t1[j]);
            }
            for (int j = 0; j < n; j++) {
                t2[j] = t1[j];
                t1[j] = 0;
            }
        }
        return max_length * max_length;
    }
};
```