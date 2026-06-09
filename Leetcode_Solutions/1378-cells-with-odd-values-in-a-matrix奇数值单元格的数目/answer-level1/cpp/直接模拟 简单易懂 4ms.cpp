### 解题思路
直接模拟题目行为

### 代码

```cpp
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices)
    {
        vector<vector<int>> vec(n, vector<int> (m, 0));
        int len = indices.size();
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < n; j++)
                vec[j][indices[i][1]]++;
            for (int k = 0; k < m; k++)
                vec[indices[i][0]][k]++;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                //cout << vec[i][j];
                if (vec[i][j] & 1) cnt++;
            }
            //cout << '\n';
        }
        return cnt;
    }
};
```