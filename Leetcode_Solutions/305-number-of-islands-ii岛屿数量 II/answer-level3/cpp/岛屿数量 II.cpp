#### 方法 1：暴力

**算法**

复用问题「[200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/description/)」的代码，对于每一次 _addLand_ 操作，每次操作后调用问题 200 的 `numIslands` 函数去获得岛屿数量。

```c++ [solution-C++]
class Solution {
private:
  void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited) {
    int nr = grid.size();
    int nc = grid[0].size();

    if (r < 0 || c < 0 || r >= nr || c >= nc || grid[r][c] == '0' || visited[r][c]) return;

    visited[r][c] = true;
    dfs(grid, r - 1, c, visited);
    dfs(grid, r + 1, c, visited);
    dfs(grid, r, c - 1, visited);
    dfs(grid, r, c + 1, visited);
  }

  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    int nc = grid[0].size();

    vector<vector<bool>> visited (nr, vector<bool>(nc, false));
    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1' && !visited[r][c]) {
          ++num_islands;
          dfs(grid, r, c, visited);
        }
      }
    }

    return num_islands;
  }

public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> ans;
    vector<vector<char>> grid (m, vector<char>(n, '0'));
    for (auto pos : positions) {
      grid[pos.first][pos.second] = '1';
      ans.push_back(numIslands(grid));
    }

    return ans;
  }
};
```

```java [solution-Java]
class Solution {
  void dfs(char[][] grid, int r, int c, boolean[][] visited) {
    int nr = grid.length;
    int nc = grid[0].length;

    if (r < 0 || c < 0 || r >= nr || c >= nc || grid[r][c] == '0' || visited[r][c]) {
      return;
    }

    visited[r][c] = true;
    dfs(grid, r - 1, c, visited);
    dfs(grid, r + 1, c, visited);
    dfs(grid, r, c - 1, visited);
    dfs(grid, r, c + 1, visited);
  }

  public int numIslands(char[][] grid) {
    if (grid == null || grid.length == 0) {
      return 0;
    }

    int nr = grid.length;
    int nc = grid[0].length;
    boolean[][] visited = new boolean[nr][nc];
    for (boolean[] row : visited) {
      Arrays.fill(row, false);
    }
    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1' && !visited[r][c]) {
          ++num_islands;
          dfs(grid, r, c, visited);
        }
      }
    }

    return num_islands;
  }

  public List<Integer> numIslands2(int m, int n, int[][] positions) {
    List<Integer> ans = new ArrayList<>();
    char[][] grid = new char[m][n];
    for (char[] row : grid) {
      Arrays.fill(row, '0');
    }
    for (int[] pos : positions) {
      grid[pos[0]][pos[1]] = '1';
      ans.add(numIslands(grid));
    }
    return ans;
  }
}
```

**复杂度分析**

* 时间复杂度： $O(L \times m \times n)$ ，其中 $L$ 是操作的数目， $m$ 是行数， $n$ 是列数。

* 空间复杂度： $O(m \times n)$ ，`grid` 和 `visited` 两个二维数组的空间开销。

#### 方法 2： 哈希表

**算法**

用 `HashMap` 将一个岛屿在地图上的坐标映射到它的岛屿编号 island_ID （从 0 开始）。

对每一个在 (row, col) 的 _addLand_ 操作，检查它相邻的邻居里是否有在 `HashMap` 中，并将有 `island_ID` 的邻居放到一个集合 `set` 中（这样每个元素都是唯一的）。
- 如果 `set` 是空的，那么 (row, col) 位置的岛屿形成了一个新的岛屿（island_ID 线性自增 1 ）。
- 如果 `set` 仅包含一个 island_ID ，那么新的陆地属于一个已经存在的岛屿，且岛屿的 island_ID 保持不变。
- 如果 `set` 包含超过一个 island_ID ，那么新的陆地会把这些岛屿连接成一个岛屿，我们需要遍历 `HashMap` 更新这个信息（非常耗时！），然后相应地减少岛屿的数目。

```c++ [solution-C++]
class Solution {
public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> ans;
    unordered_map<int, int> land2id; // land index : island ID
    int num_islands = 0;
    int island_id = 0;
    for (auto pos : positions) {
      int r = pos.first;
      int c = pos.second;
      // check pos's nei***ors to see if they are in the existing islands or not
      unordered_set<int> overlap; // how many existing islands overlap with 'pos'
      if (r - 1 >= 0 && land2id.count((r-1) * n + c)) overlap.insert(land2id[(r-1) * n + c]);
      if (r + 1 < m && land2id.count((r+1) * n + c)) overlap.insert(land2id[(r+1) * n + c]);
      if (c - 1 >= 0 && land2id.count(r * n + c - 1)) overlap.insert(land2id[r * n + c - 1]);
      if (c + 1 < n && land2id.count(r * n + c + 1)) overlap.insert(land2id[r * n + c + 1]);

      if (overlap.empty()) { // no overlap
        ++num_islands;
        land2id[r * n + c] = island_id++; // new island
      } else if (overlap.size() == 1) { // one overlap, just append
        auto it = overlap.begin();
        land2id[r * n + c] = *it;
      } else { // more than 1 overlaps, merge
        auto it = overlap.begin();
        int root_id = *it;
        for (auto& kv : land2id) { // update island id
          if (overlap.count(kv.second)) kv.second = root_id;
        }
        land2id[r * n + c] = root_id;
        num_islands -= (overlap.size() - 1);
      }

      ans.push_back(num_islands);
    }

    return ans;
  }
};
```

```java [solution-Java]
class Solution {
  public List<Integer> numIslands2(int m, int n, int[][] positions) {
    List<Integer> ans = new ArrayList<>();
    HashMap<Integer, Integer> land2id = new HashMap<Integer, Integer>();
    int num_islands = 0;
    int island_id = 0;

    for (int[] pos : positions) {
      int r = pos[0], c = pos[1];
      Set<Integer> overlap = new HashSet<Integer>();

      if (r - 1 >= 0 && land2id.containsKey((r-1) * n + c)) {
        overlap.add(land2id.get((r-1) * n + c));
      }
      if (r + 1 < m && land2id.containsKey((r+1) * n + c)) {
        overlap.add(land2id.get((r+1) * n + c));
      }
      if (c - 1 >= 0 && land2id.containsKey(r * n + c - 1)) {
        overlap.add(land2id.get(r * n + c - 1));
      }
      if (c + 1 < n && land2id.containsKey(r * n + c + 1)) {
        overlap.add(land2id.get(r * n + c + 1));
      }

      if (overlap.isEmpty()) {
        ++num_islands;
        land2id.put(r * n + c, island_id++);
      } else if (overlap.size() == 1) {
        land2id.put(r * n + c, overlap.iterator().next());
      } else {
        int root_id = overlap.iterator().next();
        for (Map.Entry<Integer, Integer> entry : land2id.entrySet()) {
          int k = entry.getKey();
          int id = entry.getValue();
          if (overlap.contains(id)) {
            land2id.put(k, root_id);
          }
        }
        land2id.put(r * n + c, root_id);
        num_islands -= (overlap.size() - 1);
      }
      ans.add(num_islands);
    }

    return ans;
  }
}
```

**复杂度分析**

* 时间复杂度： $O(L^2)$ ，对于每一次操作，我们遍历整个 HashMap 更新岛屿 id 信息，这个操作的开销是 $O(L)$ 的。

* 空间复杂度： `HashMap` 的空间开销为 $O(L)$ 。

附： C++ 的解法 1409ms 运行时间通过了，但是 Java 的解法超时了(TLE)。

#### 方法 3：并查集

**想法**

把二维的网格图当做一个无向图（以邻接矩阵的方式组织），横向或者纵向相邻的节点之间有一条值为 `1` 的边，那么问题就变成了每次 _addLand_ 操作之后在图中寻找连通部分的问题。

**算法**

使用并查集这一数据结构，大小为 `m*n` ，在图中保存所有的节点，并初始化每个节点的父节点为 `-1` 表示一个空的图。我们的目标是在每次 _addLand_ 操作以后用新的陆地更新并查集并维护每块陆地所属的岛屿。

对于每个在 (row, col) 的 _addLand_ 操作，将它与邻居合并。如果它的邻居没有陆地，就初始化一个新的岛屿（将父节点设为它自己）。

以下动画可以更好地说明此算法（包括并查集如何进行 _路径压缩_ 和 _按秩合并_）：

<![image.png](https://pic.leetcode-cn.com/e153882d4f07eb61ccf392004a6059e422c241d387c209b2c94c1d1f6d0b543e-image.png),![image.png](https://pic.leetcode-cn.com/870d2ce295b10b3f874b203a137740b10ffdb91f1bf5ab8be83c9c2f278c03a7-image.png),![image.png](https://pic.leetcode-cn.com/841601f44fd47df18f4f59df61be79c1cf087933f5f3cfa76f1f4cf562ac00f4-image.png),![image.png](https://pic.leetcode-cn.com/059f29d9e44ac171bf8aabef20040d6e7f23604b03ddfa51432ded4427b7150d-image.png),![image.png](https://pic.leetcode-cn.com/882acdc3dcbe48a236d6ff351d740d228ea981d7d9e724b177a2a7d6c4dd95e2-image.png),![image.png](https://pic.leetcode-cn.com/6c52a998873d5e0ef657aaca974553e7728f0f15d0d9dc14444ed4fc9d5297fe-image.png),![image.png](https://pic.leetcode-cn.com/599a6cee1e2a12d8b4776e9963044ad25dd6c6c3bdc84b02460160dd65c972e9-image.png),![image.png](https://pic.leetcode-cn.com/b383c376a47e4cafd0cf9e004ca3f49100c193791dcf233768f9b0f2a72c0bf0-image.png),![image.png](https://pic.leetcode-cn.com/d6758da9fdfd62c6965f920487cbc6ae7d675ce103a8188b2a0687779b4cc8e6-image.png),![image.png](https://pic.leetcode-cn.com/f0185d4197266cd52897e521c0786f8ba31567fd4beb80ff4aca76dd3675b96f-image.png),![image.png](https://pic.leetcode-cn.com/dc8c550acef8a262535dbcf9f687673ef27ceddc213424433d4a61d016743b2e-image.png),![image.png](https://pic.leetcode-cn.com/e470d87e3ffca8f98bfd1b866ae0870726ed824d5e170850f737fc34b01118db-image.png),![image.png](https://pic.leetcode-cn.com/8e178720b8e8928d2b3c7fb733ab9877d4a5cc98edb71c2803c44e2d7569e756-image.png),![image.png](https://pic.leetcode-cn.com/8c6d22c25307a371d29f49a001581e8b0d84423c5ef720ff1f0b41ab7e4bc45c-image.png),![image.png](https://pic.leetcode-cn.com/5843019cd91aa4da26c4bf922cdeac8981919ea6775384603c6fbddf374e05e7-image.png)>

```c++ [solution-C++]
class UnionFind {
public:
  UnionFind(int N) {
    count = 0;
    for (int i = 0; i < N; ++i) {
      parent.push_back(-1);
      rank.push_back(0);
    }
  }

  bool isValid(int i) const {
    return parent[i] >= 0;
  }

  void setParent(int i) {
    parent[i] = i;
    ++count;
  }

  int find(int i) { // path compression
    if (parent[i] != i) parent[i] = find(parent[i]);
    return parent[i];
  }

  void Union(int x, int y) { // union with rank
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
      else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
      else {
        parent[rooty] = rootx; rank[rootx] += 1;
      }
      --count;
    }
  }

  int getCount() const {
    return count;
  }

private:
  vector<int> parent;
  vector<int> rank;
  int count; // # of connected components
};

class Solution {
public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> ans;
    UnionFind uf (m * n);

    for (auto& pos : positions) {
      int r = pos.first;
      int c = pos.second;
      // check pos's nei***ors to see if they are in the existing islands or not
      vector<int> overlap; // how many existing islands overlap with 'pos'
      if (r - 1 >= 0 && uf.isValid((r-1) * n + c)) overlap.push_back((r-1) * n + c);
      if (r + 1 < m && uf.isValid((r+1) * n + c)) overlap.push_back((r+1) * n + c);
      if (c - 1 >= 0 && uf.isValid(r * n + c - 1)) overlap.push_back(r * n + c - 1);
      if (c + 1 < n && uf.isValid(r * n + c + 1)) overlap.push_back(r * n + c + 1);

      int index = r * n + c;
      uf.setParent(index);
      for (auto i : overlap) uf.Union(i, index);
      ans.push_back(uf.getCount());
    }

    return ans;
  }
};
```

```java [solution-Java]
class Solution {   
  class UnionFind {
    int count; // # of connected components
    int[] parent;
    int[] rank;

    public UnionFind(char[][] grid) { // for problem 200
      count = 0;
      int m = grid.length;
      int n = grid[0].length;
      parent = new int[m * n];
      rank = new int[m * n];
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == '1') {
            parent[i * n + j] = i * n + j;
            ++count;
          }
          rank[i * n + j] = 0;
        }
      }
    }

    public UnionFind(int N) { // for problem 305 and others
      count = 0;
      parent = new int[N];
      rank = new int[N];
      for (int i = 0; i < N; ++i) {
        parent[i] = -1;
        rank[i] = 0;
      }
    }

    public boolean isValid(int i) { // for problem 305
      return parent[i] >= 0;
    }

    public void setParent(int i) {
      parent[i] = i;
      ++count;
    }

    public int find(int i) { // path compression
      if (parent[i] != i) parent[i] = find(parent[i]);
      return parent[i];
    }

    public void union(int x, int y) { // union with rank
      int rootx = find(x);
      int rooty = find(y);
      if (rootx != rooty) {
        if (rank[rootx] > rank[rooty]) {
          parent[rooty] = rootx;
        } else if (rank[rootx] < rank[rooty]) {
          parent[rootx] = rooty;
        } else {
          parent[rooty] = rootx; rank[rootx] += 1;
        }
        --count;
      }
    }

    public int getCount() {
      return count;
    }
  }

  public List<Integer> numIslands2(int m, int n, int[][] positions) {
    List<Integer> ans = new ArrayList<>();
    UnionFind uf = new UnionFind(m * n);

    for (int[] pos : positions) {
      int r = pos[0], c = pos[1];
      List<Integer> overlap = new ArrayList<>();

      if (r - 1 >= 0 && uf.isValid((r-1) * n + c)) overlap.add((r-1) * n + c);
      if (r + 1 < m && uf.isValid((r+1) * n + c)) overlap.add((r+1) * n + c);
      if (c - 1 >= 0 && uf.isValid(r * n + c - 1)) overlap.add(r * n + c - 1);
      if (c + 1 < n && uf.isValid(r * n + c + 1)) overlap.add(r * n + c + 1);

      int index = r * n + c;
      uf.setParent(index);
      for (int i : overlap) uf.union(i, index);
      ans.add(uf.getCount());
    }

    return ans;
  }
}
```

**复杂度分析**

* 时间复杂度： $O(m \times n + L)$ ，其中 $L$ 是操作的数目， $m$ 是行数， $n$ 是列数。需要 $O(m \times n)$ 的时间去初始化并查集， $O(L)$ 的时间去处理岛屿位置。使用路径压缩和按秩合并的情况下，并查集操作的时间可以视为常数时间

* 空间复杂度： $O(m \times n)$ 。并查集所需的空间。
