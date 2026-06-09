### 解题思路
在一个格子中判断上、下、左、右四个格子哪个符合标准，如果符合标准就走到这个格子中，记录+1，再从这个格子中寻找。

### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int res = 0;
        vector<vector<int>>cache(m, vector<int>(n, 0));
        movingCountHelper(m, n, 0, 0, k, res, cache);
        return res;
    }

        void movingCountHelper(int m, int n, int rowStart, int columnStart, int k, int& res, vector<vector<int>>& cache) {
        if (cache[rowStart][columnStart] == 0  && decodeNum(rowStart) + decodeNum(columnStart) <= k) {
            res += 1;
            cache[rowStart][columnStart] = 1;
        }
        if (rowStart - 1 >= 0 && decodeNum(rowStart - 1) + decodeNum(columnStart) <= k && cache[rowStart - 1][columnStart] == 0) {
            res += 1;
            cache[rowStart - 1][columnStart] = 1;
            movingCountHelper(m, n, rowStart - 1, columnStart, k, res, cache);
        }
        if (columnStart - 1 >= 0 && decodeNum(rowStart) + decodeNum(columnStart - 1) <= k && cache[rowStart][columnStart - 1] == 0) {
            res += 1;
            cache[rowStart][columnStart - 1] = 1;
            movingCountHelper(m, n, rowStart, columnStart - 1, k, res, cache);
        }
        if (rowStart + 1 < m && decodeNum(rowStart + 1) + decodeNum(columnStart) <= k && cache[rowStart + 1][columnStart] == 0) {
            res += 1;
            cache[rowStart + 1][columnStart] = 1;
            movingCountHelper(m, n, rowStart + 1, columnStart, k, res, cache);
        }
        if (columnStart + 1 < n && decodeNum(rowStart) + decodeNum(columnStart + 1) <= k && cache[rowStart][columnStart + 1] == 0) {
            res += 1;
            cache[rowStart][columnStart + 1] = 1;
            movingCountHelper(m, n, rowStart, columnStart + 1, k, res, cache);
        }
    }

    int decodeNum(int n) {
        int res = 0;
        while(n != 0) {
            res += n % 10;
            n = n / 10;
        }
        return res;
    }
};
```