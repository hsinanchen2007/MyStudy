### 解题思路
&emsp; 看到这种上下左右，~~居然先想到的是元胞自动机~~,就想着可能是BFS啦，~~但是看到是简单我以为是一个规律题~~。
&emsp; 我来复习一下, 巩固下自己的记忆：
- 碰到网格找路径的，求连通的，可以$BFS,DFS$。
- 遇到这种上下左右，类似扩展，用$BFS$,假如加上了层数等具有周期性的概念(仔细体会),统计$queue$的$size$用于确定每个“周期”。   

&emsp; 这个题目，最后我还是利用的比较套路化的模板解决的，这题比较麻烦的是出发点的选取问题，因此做一个预处理是比较好的方法:  
&emsp; **思路**:
1. 首先进行初始化，变量$zero$记录空地，变量$one$记录新鲜橘子🍊，以及一个记录腐烂橘子的队列(这里我们存的是pair)
2. 预处理，将**腐烂橘子入队**，统计$one$，$zero$的数量，并在结束后进行一次特判(解决了，不存在腐烂橘子，和不存在新鲜橘子的情况)
3. 然后就是常规的$BFS$了：
    - 先确定$queue$的长度，确定循环多少次之后进入下一分钟
    - 出队一个，判断是否越界以及周围是否有新鲜橘子🍊，假如有`-- one`(新鲜橘子的数量减一)， 然后将其入队
    - 结束条件是`one == 0 || Q.empty()`也就是**没有新鲜橘子的情况**和**每个腐烂橘子都已经感染了周围橘子的情况**
    - 最后判断是否还有新鲜橘子🍊，假如还有`return -1`,不然正常返回
### 代码

```cpp
class Solution {
    int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0, zero = 0, one = 0, len = 0;
        std::queue< std::pair<int, int> >Q;
        for (int i = 0; i < grid.size(); ++ i){
            for (int j = 0; j < grid[0].size(); ++ j){
                if (grid[i][j] == 2) Q.push(make_pair(i, j)); // 烂橘子入队！
                else grid[i][j] ? ++ one : ++ zero; // 判断是好橘子🍊还是空地
            }
        }
        if ((Q.empty() && one) || !one) return one ? -1 : 0; // 特判一下
        
        while (!Q.empty() && one) {
            len = Q.size(); // 🚩 确定循环次数
            for (int k = 0; k < len; ++ k){
                std::pair<int, int> p = Q.front(); Q.pop();
                for (int i = 0; i < 4; ++ i){
                    int tx = p.first+go[i][0], ty = p.second+go[i][1];
                    if (tx >= 0 && tx < grid.size() && ty >= 0 && ty < grid[0].size()
                    && grid[tx][ty] == 1){
                        -- one;
                        grid[tx][ty] = 2; // 类似标记一下是否访问过,不然下一次就会出现被重复感染的情况
                        Q.push(make_pair(tx, ty));
                    }
                }
            }
            ++ ans;
        }

        return one == 0 ? ans : -1;
    }
};
```