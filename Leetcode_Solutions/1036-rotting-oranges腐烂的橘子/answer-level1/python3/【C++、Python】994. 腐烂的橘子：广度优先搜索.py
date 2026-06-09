### 广度优先搜索 ###
- 可以结合二叉树层序遍历进行理解
![994.gif](https://pic.leetcode-cn.com/1d892bedf35147943227f5e8c4669a4d12362b98c6c90126fd9a8ebedffcabe3-994.gif)

#### 思路 ####
- 首先需要遍历整个网格，将新鲜的橘子加入集合，将腐烂的橘子加入队列
- 当腐烂队列不为空时，循环
  - 每次循环开始时，记录下队列当前的长度（即前一分钟新增腐烂橘子的数目）
  - 对于每个当前已经腐烂的橘子，将其四周相邻的新鲜橘子从新鲜集合中移除，加入腐烂队列
  - 若本次循环有新腐烂的橘子，分钟数增加一
- 最后，若新鲜集合为空，返回记录的分钟数，否则返回`-1`
#### 代码 ####
```cpp []
class Solution {
public:
    typedef pair<int, int> pos;
    vector<pos> dirs{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        set<pos> fresh;
        queue<pos> rotten;
        int R = grid.size(), C = grid[0].size(), res = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 1) fresh.insert({i, j});
                else if (grid[i][j] == 2) rotten.push({i, j});
            }
        }
        while (!rotten.empty()) {
            int rSize = rotten.size(), fSize = fresh.size();
            for (int i = 0; i < rSize; ++i) {
                auto &&[x, y] = rotten.front();
                for (auto &&[dx, dy]: dirs) {
                    pos tmp = make_pair(x + dx, y + dy);
                    if (fresh.erase({tmp.first, tmp.second})) rotten.push(tmp);
                }
                rotten.pop();
            }
            res += fresh.size() < fSize;
        }
        return fresh.empty() ? res : -1;
    }
};
```
```python []
class Solution:
    def __init__(self):
        self.dirs = ((-1, 0), (0, -1), (1, 0), (0, 1))
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rotten, fresh = collections.deque(), set()
        R, C, res = len(grid), len(grid[0]), 0
        for i in range(R):
            for j in range(C):
                if grid[i][j] == 1: fresh.add((i, j))
                elif grid[i][j] == 2: rotten.append((i, j)) 
        while rotten:
            rSize, fSize = len(rotten), len(fresh)
            for _ in range(rSize):
                x, y = rotten.popleft()
                for dx, dy in self.dirs:
                    tmp = (x + dx, y + dy)
                    if tmp in fresh:
                        fresh.remove(tmp)
                        rotten.append(tmp)
            res += len(fresh) < fSize
        return -1 if fresh else res
```
#### 复杂度分析 ####
- 时间复杂度`O(R * C)`
- 空间复杂度`O(R * C)`