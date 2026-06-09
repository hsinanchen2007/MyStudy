预期的复杂度应是：最坏计算复杂度 $O(rc \times \log(rc))$；内存复杂度最坏 $O(rc)$，其中 $r$ 与 $c$ 分别指代矩阵行列数量。最坏情况一般会出现在答案 `cost` 较小时。对 `pair<int, int>` 有适当的 Hash 的情况下，计算复杂度有可能提高到 $O(rc)$。

这道题在竞赛时并没有完成，是事后完成的 (被第三题的低级错误卡了 T.T)。高深的 Dijkstra 方法我也不会啊，不照着参考资料大概是编不出来 T.T 下面的题解大概还蛮简单粗暴的。

## 大体思路

- 我们首先会从格点 (0,0) 沿着题目给的 `grid` 可能的路径遍历一遍，找到所有一次性能到达的格点，即 `cost = 0` 的格点；
- 上述格点临近一格的格点会是 `cost = 1` 的格点。遍历一遍可能的 `grid` 给的路径，能得到所有 `cost = 1` 的格点；
- 上述 `cost = 1` 临近格点就是 `cost = 2` 格点，以此类推。
- 任何时候，只要遍历到了最后的终点，就立即停止循环并返回当前的 `cost`。

一个具体的例子可以是下图：
- 输入数据：`[[1,4,4],[2,2,1],[1,1,3]]`，预期结果：2

![幻灯片1.PNG](https://pic.leetcode-cn.com/5e9d2b27fe19fd91001c2329f39ad6a7b42df7d54a1c9601fc17ca10a4b09b9c-%E5%B9%BB%E7%81%AF%E7%89%871.PNG)


## 具体实现

具体的实现过程代码并不太长，但对我来说一直很不容易写正确。我就用下面的图示给出一种遍历过程。
其中：
- 遍历的循环是三层循环，
- 第一层 `while (!cost_cur.empty())` 每次更新时增加 `cost` 的值；
- 第二层 `for (pair<int, int> coord : cost_cur)` 更新的是图中绿色指针 (`coord` 即是绿色指针的坐标)；
- 第三层 `while (true)` 更新的是图中红色指针 (`r` 与 `c` 即是红色指针的坐标分量)。

程序与图片中，
- `INFTY` 是一个很大的数；我们假设返回的 `cost` 不可能比它还大，因此用来初始化 `grid_cost` 矩阵；
- `r_step`, `c_step` 是用来找当前格点的下一个路径点；
- `grid_cost` 储存从初始点 (0,0) 到任意格点的代价；
- `cost_cur` 表示循环过程中，当前代价 `cost` 的路径出发格点的坐标 (不是所有代价为 `cost` 的格点)；
- `cost_next` 表示循环过程中，下一次会作为代价为 `cost + 1` 的路径出发点的坐标。

<![幻灯片2.PNG](https://pic.leetcode-cn.com/35a45f4b619eba89ec725417b8dee2d4afc6de4437fb88ad99312a5ddfef297e-%E5%B9%BB%E7%81%AF%E7%89%872.PNG),![幻灯片3.PNG](https://pic.leetcode-cn.com/b53b328ee1d745a9b0ac0ac656fe839c52bd4a25bdb54db56e389c3b58355ed2-%E5%B9%BB%E7%81%AF%E7%89%873.PNG),![幻灯片4.PNG](https://pic.leetcode-cn.com/ba24be0deace99b5a9d2007a287e647a1afd0a4177be69a90d36038ad60de60e-%E5%B9%BB%E7%81%AF%E7%89%874.PNG),![幻灯片5.PNG](https://pic.leetcode-cn.com/db685f2251a9e782d0ead0efe328508c1575d8e7e8a7899bde837379ff1fc413-%E5%B9%BB%E7%81%AF%E7%89%875.PNG),![幻灯片6.PNG](https://pic.leetcode-cn.com/2b502d29f49edc4fd878d89a81458e0d9c6c0e72286697a4b4544cd9e96b7e4d-%E5%B9%BB%E7%81%AF%E7%89%876.PNG),![幻灯片7.PNG](https://pic.leetcode-cn.com/2335d7d154cdd24ffb9f4e3280497a05cc8db74f2941c0d7f5afb8183b6618ea-%E5%B9%BB%E7%81%AF%E7%89%877.PNG),![幻灯片8.PNG](https://pic.leetcode-cn.com/ce3b32901c25b88461a1d42667c4074c10dba709bd66eabe09365d67a00b85c9-%E5%B9%BB%E7%81%AF%E7%89%878.PNG),![幻灯片9.PNG](https://pic.leetcode-cn.com/55629d4ed7baf05392d8da56a64ccda27dbdc3c8adf8d91202ae2efbed67e0c1-%E5%B9%BB%E7%81%AF%E7%89%879.PNG),![幻灯片10.PNG](https://pic.leetcode-cn.com/602e42961d4ffa77f07e714213b3b0a6393df16168bcecc14fdee0182635c1c3-%E5%B9%BB%E7%81%AF%E7%89%8710.PNG),![幻灯片11.PNG](https://pic.leetcode-cn.com/282b63b55a144e0a6842e6bf7f1d847dc67a7d7d87b8ef15fcfee3f9fa964add-%E5%B9%BB%E7%81%AF%E7%89%8711.PNG),![幻灯片12.PNG](https://pic.leetcode-cn.com/66a7ac977a99ae901e6b077910ecaa4186063e5e7f79c7ea707042f8ec4100d9-%E5%B9%BB%E7%81%AF%E7%89%8712.PNG),![幻灯片13.PNG](https://pic.leetcode-cn.com/aac448bfd027ed966c3df85db8c5fb792e385e367f3a579e4a99a9d6da0cedd6-%E5%B9%BB%E7%81%AF%E7%89%8713.PNG),![幻灯片14.PNG](https://pic.leetcode-cn.com/7f0e0f32d7175025f7a502c06cd3d00af579282e6ccbe40972307a8a1ad5522f-%E5%B9%BB%E7%81%AF%E7%89%8714.PNG),![幻灯片15.PNG](https://pic.leetcode-cn.com/fd063e047229dc4a5f7827b20914d5250babffc33e4391b58a525050f8177c1a-%E5%B9%BB%E7%81%AF%E7%89%8715.PNG)>

由于其中使用到了有序集合的插入，因此时间复杂度是 $O(r c \times \log(r c))$。

被插入的集合是矩阵的行与列的索引指标对；如果能对该指标对进行 Hash，那么复杂度可以降到 $O(r c)$。但我自己试了一下用 unordered_set 替换 set，似乎耗时并没有下降。可能频繁的内存 new 和 delete 是耗时的主要原因。

## 代码

大体上执行时间是 100ms。

```c++
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int INFTY = 1000000;
        if (grid.empty() || grid.front().empty()) return 0;
        int r_size = grid.size(), c_size = grid.front().size();
        vector<int> r_step{ INFTY, 0, 0, 1, -1 };
        vector<int> c_step{ INFTY, 1, -1, 0, 0 };
        
        vector<vector<int>> grid_cost(r_size, vector<int>(c_size, INFTY));
        set<pair<int, int>> cost_next, cost_cur;
        
        cost_cur.insert(make_pair(0, 0));
        int cost = 0;
        while (!cost_cur.empty()) {
            cost_next.clear();
            for (pair<int, int> coord : cost_cur) {
                int r = coord.first, c = coord.second;
                while (true) {
                    if (r < 0 || r >= r_size || c < 0 || c >= c_size) break;
                    if (grid_cost[r][c] <= cost) break;
                    grid_cost[r][c] = cost;
                    if (r == r_size - 1 && c == c_size - 1) return cost;
                    if (r > 0          && grid_cost[r - 1][c] > cost) cost_next.insert(make_pair(r - 1, c));
                    if (r < r_size - 1 && grid_cost[r + 1][c] > cost) cost_next.insert(make_pair(r + 1, c));
                    if (c > 0          && grid_cost[r][c - 1] > cost) cost_next.insert(make_pair(r, c - 1));
                    if (c < c_size - 1 && grid_cost[r][c + 1] > cost) cost_next.insert(make_pair(r, c + 1));
                    int r_next = r + r_step[grid[r][c]];
                    int c_next = c + c_step[grid[r][c]];
                    r = r_next, c = c_next;
                }
            }
            swap(cost_cur, cost_next);
            cost += 1;
        }
        assert(false);
        return 0;
    }
};
```

