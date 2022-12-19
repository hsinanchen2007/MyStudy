![QQ图片20190729205258.png](https://pic.leetcode-cn.com/9ae168f94dd1624046ee43629a3dc103898a41e16bba87cba717f2ff4c6c13cc-QQ%E5%9B%BE%E7%89%8720190729205258.png)

```
class UF {
  // 并查集类
private:
  vector<int>parents;
  // 并查集 记录父亲
public:
  int cnt;
  //记录连接个数 其实应该写一个get方法把它变成private的 但是我懒得搞了。。
  UF(vector<vector<char>> matrix) {
    parents = vector<int>(matrix.size() * matrix[0].size());
    
    // 生成一个 01234...的连续序列
    int count = 0;
    for_each(parents.begin(), parents.end(), [&count](auto& num) {num = count++; });

    cnt = 0;
  }
  int find(int node) {
    // 并查集 寻找父亲操作
    while (parents[node] != node) {
      parents[node] = parents[parents[node]];
      node = parents[node];
    }
    return node;
  }
  void union_(int node1, int node2) {
    // union操作
    auto root1 = find(node1);
    auto root2 = find(node2);
    if (root1 != root2) {
      parents[root2] = root1;
      cnt--;
    }
  }

  bool isConnected(int node1, int node2) {
    // 判断是否连接操作
    return find(node1) == find(node2);
  }
};

class Solution {
public:
  vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    vector<vector<char>>grid(m, vector<char>(n, '0'));
    // '0'表示水 '1'表示陆地
    int row_cnt = grid.size();
    int col_cnt = grid[0].size();
    int index = 0;
    UF uf(grid);
    vector<int>res(positions.size());
    for (auto& position : positions) {

      int i = position[0];
      int j = position[1];

      if (grid[i][j] == '1') {
        // 检查是否已经变化过 如果已经是陆地过则跳过
        // 直接用之前的节点数
        res[index++] = (uf.cnt);
        continue;
      }

      // 先增加一个联通节点 若该节点与其他节点连接 则会在union操作中减少节点个数

      uf.cnt += 1;
      grid[i][j] = '1';
      int cur_cnt = i * col_cnt + j;

      if (i != 0) {
        //检查左边
        if (grid[i - 1][j] == '1') {
          if (!uf.isConnected(cur_cnt, (i - 1) * col_cnt + j)) {
            // 未连接 则连接 （其实可以省 因为新节点肯定没有与旧节点连接）
            uf.union_(cur_cnt, (i - 1) * col_cnt + j);
          }
        }
      }
      if (i != row_cnt - 1) {
        // 检查右边
        if (grid[i + 1][j] == '1') {
          if (!uf.isConnected(cur_cnt, (i + 1) * col_cnt + j)) {
            uf.union_(cur_cnt, (i + 1) * col_cnt + j);
          }
        }
      }
      if (j != 0) {
        //检查上面
        if (grid[i][j - 1] == '1') {
          if (!uf.isConnected(cur_cnt, (i)* col_cnt + j - 1)) {
            uf.union_(cur_cnt, (i)* col_cnt + j - 1);
          }
        }
      }
      if (j != col_cnt - 1) {
        // 检查下面
        if (grid[i][j + 1] == '1') {
          if (!uf.isConnected(cur_cnt, (i)* col_cnt + j + 1)) {
            uf.union_(cur_cnt, (i)* col_cnt + j + 1);
          }
        }
      }
      // 当前操作赋值
      res[index++] = (uf.cnt);
    }
    return res;
  }
};
```
