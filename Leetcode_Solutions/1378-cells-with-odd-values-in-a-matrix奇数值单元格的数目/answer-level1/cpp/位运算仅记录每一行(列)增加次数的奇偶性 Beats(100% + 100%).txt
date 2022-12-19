通过位运算仅记录每一行和每一列增加次数的奇偶性
![image.png](https://pic.leetcode-cn.com/949b2131a01f96ddda953fdade10360c2762c49de5a024d49a2ab1686c5ad7bf-image.png)

```
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n,0);
        vector<int> cols(m,0);
        for(int i=0; i<indices.size(); i++){
            rows[indices[i][0]] ^= 1;
            cols[indices[i][1]] ^= 1;
        }
        int odd_rows = accumulate(rows.begin(), rows.end(), 0);
        int odd_cols = accumulate(cols.begin(), cols.end(), 0);
        return odd_rows * (m - odd_cols) + odd_cols * (n - odd_rows);
        
    }
};
```


