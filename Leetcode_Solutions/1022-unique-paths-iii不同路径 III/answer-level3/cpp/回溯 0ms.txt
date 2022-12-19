### 解题思路
回溯法，开始节点可以看成树的root，可以通过上下左右延伸到四个节点，然后四个节点每个都可以按上下左右继续延伸
grid记录已经用过的节点，并且递归完恢复之前的值
递归的层数，应该是所有未0和2的node和，开始节点必须选中，且选中后不能再次使用，递归前可以修改为-1。

其他细节可参考代码注释

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了63.86%的用户

### 代码

```cpp
class Solution {
public:
    // 用于loop上下左右的坐标
    int loopx[4] = {0, 0, -1, 1};
    int loopy[4] = {-1, 1, 0, 0};
    // grid 的size
    int m;
    int n;

    void inner(int& last_level, int level, int& x, int& y,
               vector<vector<int>>& grid, int& res) {
      // last_level表示要遍历所有为0和-2的node
      if (last_level == level) {
        ++res;
        return;
      }
      for (int i = 0; i < 4; ++i) {
        int nextx = x + loopx[i];
        int nexty = y + loopy[i];
        // loop坐标合法值判断
        if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n) {
          // 只有两种情况需要进行下一步，空node和结束node
          if (grid[nextx][nexty] == 0 || (level == last_level - 1 && grid[nextx][nexty] == 2)) {
            // tmp用于保存回溯的grid值，因为可能存在多个解
            int tmp = grid[nextx][nexty];
            grid[nextx][nexty] = -1;
            inner(last_level, level + 1, nextx, nexty, grid, res);
            grid[nextx][nexty] = tmp;
          }
        }
      }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
      m = grid.size();
      n = grid[0].size();
      int block_num = 0;
      int begx, begy;

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == -1) {
            ++block_num;
          }
          if (grid[i][j] == 1) {
            begx = i;
            begy = j;
            grid[i][j] = -1;
          }
        }
      }
      int res = 0;
      int last_level = m*n - block_num - 1;
      inner(last_level, 0, begx, begy, grid, res);

      return res;
    }
};
```