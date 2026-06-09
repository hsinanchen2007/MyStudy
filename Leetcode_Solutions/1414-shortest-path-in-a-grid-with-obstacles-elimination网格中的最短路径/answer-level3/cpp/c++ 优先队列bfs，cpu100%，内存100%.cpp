### 解题思路
visit数组用于记录访问到当前结点时剩余k的最大值，
当再次范围到相同结点时，如果当前剩余的k更大，则可以入队这个结点，
用优先队列加速bfs，优先出队步数更小的且剩余k数量更大的结点。

注意出队时q.top()用引用，
以及入队时用q.empty()效率比较高
### 代码

```cpp
const int path[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int kMaxM = 40;

class Solution {
 public:
  struct Node {
    Node(int i_, int j_, int k_, int step_)
        : i(i_), j(j_), k(k_), step(step_) {}

    Node() {}

    int i, j;
    int k;
    int step;

    bool operator<(const Node& other) const {
      if (step != other.step) {
        return step < other.step;
      }
      return k > other.k;
    }

    bool operator>(const Node& other) const {
      return !(*this == other) && !(*this < other);
    }

    bool operator==(const Node& other) const {
      return !(*this < other) && !(other < *this);
    }
  };

  int shortestPath(std::vector<std::vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    int visit[kMaxM][kMaxM];
    memset(&visit[0][0], -1, sizeof(visit[0][0]) * kMaxM * kMaxM);

    return bfs(grid, k, visit, m, n);
  }

  int bfs(std::vector<std::vector<int>>& grid, int k, int visit[kMaxM][kMaxM],
          int m, int n) {
    visit[0][0] = -1;
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> q;
    q.emplace(0, 0, k, 0);

    while (!q.empty()) {
      const Node& node = q.top();
      int i = node.i;
      int j = node.j;
      int step = node.step;
      int k = node.k;
      q.pop();

      if (i == m - 1 && j == n - 1) {
        return step;
      }

      for (int index = 0; index < 4; ++index) {
        int next_i = i + path[index][0];
        int next_j = j + path[index][1];
        if (next_i >= m || next_i < 0 || next_j >= n || next_j < 0) {
          continue;
        }

        int next_k = k;
        if (grid[next_i][next_j] == 1) {
          if (next_k <= 0) {
            continue;
          }
          --next_k;
        }

        if (next_k > visit[next_i][next_j]) {
          visit[next_i][next_j] = next_k;
          q.emplace(next_i, next_j, next_k, step + 1);
        }
      }
    }

    return -1;
  }
};
```