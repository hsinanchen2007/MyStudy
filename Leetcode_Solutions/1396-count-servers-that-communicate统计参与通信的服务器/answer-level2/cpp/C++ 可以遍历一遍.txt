和题解思路一样，和题解思路一样，先遍历一遍数组，记录下每行、每列的个数，然后遍历第二次数组，如果该位置的行或者列的个数大于1，则这个电脑是可以通讯的，数目加1.
如果不想遍历两边的话，可以在第一次遍历的记录着位置，然后统计行的个数，发现个数为1的行，拿出那个位置，直接去找对应的列是不是个数为1.

```
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        long R = grid.size();
        long C = grid[0].size();
        if (R == 1 && C == 1) {
            return 0;
        }
        vector<int> rowN(R), colN(C);
        for (long i=0; i<R; i++) {
            for (long j=0; j<C; j++) {
                if (grid[i][j] == 1) {
                    ++rowN[i];
                    ++colN[j];
                }
            }
        }
        int res = 0;
        for (long i=0; i<R; i++) {
            for (long j=0; j<C; j++) {
                if (grid[i][j] == 1 && (colN[j] > 1 || rowN[i] > 1)) {
                    res++;
                }
            }
        }
        return res;
    }
};
```
遍历一次的解法
```
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        long R = grid.size();
        long C = grid[0].size();
        if (R == 1 && C == 1) {
            return 0;
        }
        vector<vector<int>> rowN(R, vector<int>(0)), colN(C, vector<int>(0));
        for (long i=0; i<R; i++) {
            for (long j=0; j<C; j++) {
                if (grid[i][j] == 1) {
                    rowN[i].emplace_back(j);
                    colN[j].emplace_back(i);
                }
            }
        }
        int res = 0;
        for (auto v : rowN) {
            if (v.size() > 1) {
                res += v.size();
            } else if (v.size() == 1) {
                int j = v[0];
                if (colN[j].size() > 1) {
                    res++;
                }
            }
        }
        return res;
    }
};
```