class Solution {
    int cnt;     //新鲜橘子个数
    int dis[10][10];        //距离
    int dir_x[4]={0, 1, 0, -1};
    int dir_y[4]={1, 0, -1, 0};        //表示四个方向
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int> >Q;
        memset(dis, -1, sizeof(dis));
        cnt = 0;
        int n=(int)grid.size(), m=(int)grid[0].size(), ans = 0;  //获取行列 分别循环遍历
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j] == 2){
                    Q.push(make_pair(i, j));    //腐烂的橘子 入队
                    dis[i][j] = 0;        //自身距离为0 先标记
                }
                else if (grid[i][j] == 1) cnt += 1;   //记录开始新鲜橘子个数
            }
        }
        while (!Q.empty()){    //当队列不为空 也就是腐烂感染的过程
            pair<int,int> x = Q.front();Q.pop();   //先获取队头元素（腐烂橘子感染源） 再出队
            for (int i = 0; i < 4; ++i){
                int tx = x.first + dir_x[i];
                int ty = x.second + dir_y[i];    //四个方向进行感染
                if (tx < 0|| tx >= n || ty < 0|| ty >= m|| ~dis[tx][ty] || !grid[tx][ty]) continue;  //排除特殊情况 不能感染空格子 不能感染距离为0的已腐烂橘子 之后用析构函数释放内存
                dis[tx][ty] = dis[x.first][x.second] + 1;   //感染一次 计数加距离
                Q.push(make_pair(tx, ty));         //再令此时新感染的橘子入队
                if (grid[tx][ty] == 1){
                    cnt -= 1;      //感染一次 新鲜橘子个数减一
                    ans = dis[tx][ty];  //答案就是距离（或者理解为次数） 因为速度是1 所以时间数值上等于距离
                    if (!cnt) break;  //cnt为0时 也就是全部感染完了 没有新鲜橘子了 循环就要终止
                    //如果cnt不为0 本身也都遍历了
                }
            }
        }
        return cnt ? -1 : ans; //三元运算符 cnt不为0时输出-1 也就是都感染完了还有存在的新鲜橘子 
        //当cnt为0时 输出ans 也就是都感染完毕了 输出答案（时间）
    }
};

