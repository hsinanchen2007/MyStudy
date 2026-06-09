### 解题思路
没什么算法，就是转圈圈


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> moves = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

    bool inArea(int i, int j, int n)
    {
        if (i >= 0 && i < n && j >= 0 && j < n) {
            return true;
        }

        return false;
    }


    vector<vector<int>> generateMatrix(int n)
    {
        if (n <= 0) {
            return vector<vector<int>>();
        }

        vector<vector<int>> result = vector<vector<int>>(n, vector<int>(n, 0));
        vector<vector<int>> visit = vector<vector<int>>(n, vector<int>(n, 0));

        int i = 0;
        int j = 0;
        int count = 1;
        int m  = 0;
        while (true) {
            result[i][j] = count;
            visit[i][j] = 1;
            count++;
            if (count > n * n) {
                break;
            }
            int newi = i + moves[m][0];
            int newj = j + moves[m][1];

            if (inArea(newi, newj, n) && !visit[newi][newj]) {
                i = newi;
                j = newj;
            } else {
                m = (m + 1) % moves.size();
                i = i + moves[m][0];
                j = j + moves[m][1];
            }
        }

        return result;
    }
};
```