### 解题思路
![1.png](https://pic.leetcode-cn.com/27f1779307cb51b89efb9f82a698dda8d47c1cdc4433e3ac1da69e1b30b77106-1.png)

### 代码

```cpp
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> res(n, vector<int>(m));
        for (auto cur : indices) {
            for (int i = 0; i < m; i++)
                res[cur[0]][i]++;
            for (int i = 0; i < n; i++)
                res[i][cur[1]]++;
        }

        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++)
                if(res[i][j]%2 == 1)cnt++;
        }
    return cnt;
    }
};
```