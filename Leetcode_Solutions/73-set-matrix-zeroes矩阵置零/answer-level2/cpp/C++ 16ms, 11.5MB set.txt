### 解题思路
set 是个好东西，简单来说，就是一种实现了集合的数据类型。

![image.png](https://pic.leetcode-cn.com/ab765e927aa52bc7af54ff57f767e176cf0e34224fd0f101e5388e8b08d64532-image.png)

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        set<int> row, col;
        // 建立分别关联行和列的 set 类型 row 和 col
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
        // 遍历 set 并清零
        set<int>::iterator it;
        for(int i = 0; i < n; i ++)
            for(it = col.begin(); it != col.end(); it ++)
                matrix[i][*it] = 0;
        for(int i = 0; i < m; i ++)
            for(it = row.begin(); it != row.end(); it ++)
                matrix[*it][i] = 0;
    }
};
```