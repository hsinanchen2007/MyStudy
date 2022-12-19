**关于DFS解法的思考**：
# 本文中关于DFS的说明有错。错误的原因见*执迷*大佬的评论。
因为本题中的street-type，每个块只有两个入口，当访问该块时必然是一个进一个出，从而导致：
对于所有的输入数据，只会有且只有一种行走方案。所以DFS在本题可行。
如果有丁字路口甚至十字路口呢？行走方案的数量将会**指数爆炸**，此时DFS应该是无法解决了。

## 5366. 检查网格中是否存在有效路径
典型的图的优先搜索问题。比较考验处理细节的能力。
可以借助 std::queue 来几率待搜索的点，借助 std::unordered_set 记录已访问的点。每次从 queue 的队首取出待搜索节点，记为  f，然后枚举 f 周围的四个节点，根据题目给出的 street-type 判断是否可达。

```cpp
int dx[] = {-1, 0, 1, 0};
int dy[] = { 0, 1, 0,-1};
class Solution {
public:
    bool isAccess(int cur, int next, int dir) {
        if (dir == 0){
            if((cur == 2 || cur == 5 || cur == 6) && (next == 2 || next == 3 || next == 4)) {
                return true;
            }
        }
        if (dir == 1){
            if((cur == 1 || cur == 4 || cur == 6) && (next == 1 || next == 3 || next == 5)) {
                return true;
            }
        }
        if (dir == 2){
            if((cur == 2 || cur == 3 || cur == 4) && (next == 2 || next == 5 || next == 6)) {
                return true;
            }
        }
        if (dir == 3){
            if((cur == 1 || cur == 3 || cur == 5) && (next == 1 || next == 4 || next == 6)) {
                return true;
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        set<pair<int,int>> mark;
        mark.insert(make_pair(0,0));
        while(q.empty() == false) {
            auto f = q.front(); q.pop();
            if(f.first == grid.size()-1 && f.second == grid[0].size()-1) {
                return true;
            }
            for(int i = 0; i < 4; i++) {
                auto next = make_pair(f.first + dx[i], f.second + dy[i]);
                if(mark.find(next) != mark.end()) {
                    continue;
                }
                if(next.first < 0 || next.first >= grid.size() || next.second < 0 || next.second >= grid[0].size()) {
                    continue;
                }
                if(false == isAccess(grid[f.first][f.second], grid[next.first][next.second], i)) {
                    continue;
                }
                q.push(next);
                mark.insert(next);
            }
        }
        return false;
    }
};
```
# 扫码关注 快乐加倍
![image.png](https://pic.leetcode-cn.com/1784b38a1d01ad142438a38be297158dd32343e4c3fc5d3e5aed16c2ae80d706-image.png)

![](https://pic.leetcode-cn.com/6baef4eaa8ffd4287bd5c4cb3e1b723a6a80800585e413f066c1976dcf717c0d.jpg)
