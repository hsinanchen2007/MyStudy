这道题我一开始以为不一定从树顶进行遍历，所以才会有这段代码。

下述做法可能适用于任何图结构，不一定是树；但为此复杂度至少应该是 $O(n \log n)$ 量级的。

#### 大致思路

其实思路还蛮简单的吧，就是从任何一个节点出发 BFS 遍历节点。

每次遍历都记录在自定义结构 `Status` 中：
- 自己的节点编号 `pos`
- 曾经去过的节点编号 `traversed`
- 自己的遍历概率 `prob`

更多的实现细节就放到代码中说明了。也不作具体用例说明。

#### 代码

运行大约 60ms。代码中的 `INIT_POS` 可以是任意值。题目要求从树顶遍历，因此设为 1。

```c++
class Solution {
    /// 节点信息
    struct Status {
        int pos = 0;           // 节点编号
        set<int> traversed{};  // 曾经去过的节点编号
        double prob = 0.;      // 自己当前的概率
    };
    /// 从邻接表 neighbours 中，寻找并返回当前节点 stat 下一步可以遍历的节点编号 result
    set<int> possible_nextpos(Status& stat, unordered_map<int, vector<int>>& neighbours) {
        set<int> result;
        for (int i : neighbours[stat.pos]) {
            if (stat.traversed.find(i) == stat.traversed.end())
                result.insert(i);
        }
        return result;
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        // 出发点始终是 1 号节点
        int INIT_POS = 1;
        // 构建邻接表
        unordered_map<int, vector<int>> neighbours;
        for (auto v : edges) {
            neighbours[v[0]].push_back(v[1]);
            neighbours[v[1]].push_back(v[0]);
        }
        // 构建出发点的状态
        Status stat_init;
        stat_init.pos = INIT_POS;
        stat_init.traversed.insert(INIT_POS);
        stat_init.prob = 1.;
        // 为 BFS 作准备，用向量实现
        vector<Status> all_prev{ stat_init };
        vector<Status> all_next;
        double result = 0.;
        // BFS
        for (int time = 0; time < t; ++time) {
            all_next.clear();
            if (all_prev.empty()) break;
            // 对上一步的节点作遍历
            for (auto& stat : all_prev) {
                // 先求出对于上一步 stat 而言，下一步可能的节点编号
                set<int> nextpos = possible_nextpos(stat, neighbours);
                // 如果下一步节点编号为空，那么青蛙只能原地打转。将这部分概率加到结果中。
                if (nextpos.empty()) {
                    if (stat.pos == target)
                        result += stat.prob;
                }
                // 如果下一步编号不为空，那么创建新的节点，添加到下一次循环需要遍历的节点中。
                // 但如果这一步编号是目标结果，那么我们永远不可能回到目标。这种情况要跳过。
                else {
                    if (stat.pos != target) {
                        for (int p : nextpos) {
                            all_next.push_back(stat);
                            auto& s = all_next.back();
                            s.pos = p;
                            s.traversed.insert(p);
                            s.prob /= nextpos.size();
                        }
                    }
                }
            }
            swap(all_prev, all_next);
        }
        // 最后收尾：到时间的话，如果青蛙恰好在目标点上，就将概率加上去。
        for (auto& stat : all_prev) {
            if (stat.pos == target)
                result += stat.prob;
        }
        return result;
    }
};
```