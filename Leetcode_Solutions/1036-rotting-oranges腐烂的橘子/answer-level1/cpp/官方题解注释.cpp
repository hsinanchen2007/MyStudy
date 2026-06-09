### 解题思路
─=≡Σ(((つ•̀ω•́)つ))好久不打C++，刚开始复习。
同样的思路，菜🐦渣渣写的代码比官方的多十几行。。
然后就分析了一下参考答案，可能只适合小白看。欢迎指正谢谢，大佬慢走~
大概就是用队列实现，BFS思想。(～￣▽￣)～

### 代码

```cpp
class Solution {
    int cnt;
    int dis[10][10];
    int dir_x[4]={0, 1, 0, -1}; // 右下左上四个正方向
    int dir_y[4]={1, 0, -1, 0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int> >Q; // 队列Q：存放烂橙子对
        memset(dis, -1, sizeof(dis));  // dis用-1填满
        cnt = 0;  // 记录鲜橙子个数
        int n=(int)grid.size(), m=(int)grid[0].size(), ans = 0; // n行m列
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j] == 2){           // 若橙子是烂的
                    Q.push(make_pair(i, j));    // 创建一对儿(烂橙子的坐标)，存入队列Q
                    dis[i][j] = 0;              // 第0分钟是起点
                }
                else if (grid[i][j] == 1) cnt += 1;  // 若橙子是新鲜的，记数
            }
        }
        while (!Q.empty()){  // 最初有烂橙子/还有新感染的烂橙子
            pair<int,int> x = Q.front();Q.pop(); // 开始传染
            for (int i = 0; i < 4; ++i){
                // 向四个方向感染
                int tx = x.first + dir_x[i];
                int ty = x.second + dir_y[i];
                /* 若下一步的方向过界（超出箱子了）
                or 这个方位的橙子本身已经被感染了（即：它dis[tx][ty]不是-1,~：变成补码）
                or 这个方位的橙子本身为0（是空位），则开启下一轮循环，跳过这个方位。*/
                if (tx < 0|| tx >= n || ty < 0|| ty >= m|| ~dis[tx][ty] || !grid[tx][ty]) continue;
                dis[tx][ty] = dis[x.first][x.second] + 1;// 橙子被感染的时间为它的传染源被感染时间+1
                Q.push(make_pair(tx, ty));  //把新感染的橙子的位置加到队列里
                cnt--;
                ans = dis[tx][ty];
                /* 感觉官方题解的👇这段代码没啥用啊，用👆上面两行把它替代了。
                if (grid[tx][ty] == 1){ // 如果橙子原本是新鲜的，新鲜的橙子数目-1 
                    cnt -= 1;
                    ans = dis[tx][ty];  // 记录最晚被感染的橙子被感染的时间
                    if (!cnt) break; // 没有新鲜的橙子了
                }*/
            }
        }
        return cnt ? -1 : ans; // 如果还有新鲜的橙子就返回-1，都烂了就返回ans
    }
};


```