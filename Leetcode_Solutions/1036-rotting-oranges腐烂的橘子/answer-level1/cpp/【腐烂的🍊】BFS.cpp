// ### 解题思路
// 应该是最基本的方法了。。。。
// 写的有点乱，改了半天，好多小bug

// ### 代码

// ```cpp
class Solution {
    
    // 上下左右四个方向
    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    // 定义数据结构：🍊的状态，行、列、腐烂时间
    struct Oranges{
        int row;    
        int col;
        int time=0;
    }orange_tmp, orange_new;
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        //网格为空，直接返回
        if(grid.empty() || grid[0].empty()) {
            return -1;
        }
        int m = grid.size(), n = grid[0].size();  //网格的行列数目
        // if()
        int cnt = 0;
        queue<Oranges> Q;  //腐烂🍊的队列

        // 遍历网格，将腐烂🍊放入队列
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    orange_tmp.row = i;
                    orange_tmp.col = j;
                    Q.push(orange_tmp);
                    // cout<<orange_tmp.row<<'\t'<<orange_tmp.col<<'\t'<<orange_tmp.time<<endl;
                }
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        //没有新鲜🍊，直接返回0
        if(cnt==0)
            return 0;
        // cout<<"total:"<<cnt<<endl;

        //BFS，传播🍊腐烂病毒
        int row_tmp, col_tmp, time_tmp=0;
        while(!Q.empty()){
            orange_tmp = Q.front();   //取出队列中第一个腐烂🍊
            //感染周围🍊
            for(int i = 0; i<4; i++){
                // cout<<"i:"<<i<<'\t';
                // cout<<"direction: "<<dir[i][0]<<'\t'<<dir[i][1]<<endl;
                row_tmp = orange_tmp.row + dir[i][0];
                col_tmp = orange_tmp.col + dir[i][1];
                time_tmp = orange_tmp.time;
                // cout<<row_tmp<<'\t'<<col_tmp<<'\t'<<time_tmp<<endl;
                if((row_tmp>=0)&&(row_tmp<m)&&(col_tmp>=0)&&(col_tmp<n)&&(grid[row_tmp][col_tmp]==1)){
                    grid[row_tmp][col_tmp]=2;
                    orange_new.row = row_tmp, orange_new.col = col_tmp, orange_new.time = time_tmp+1;
                    Q.push(orange_new);
                    // cout<<orange_tmp.time<<endl;
                    cnt--;
                }
            }
            Q.pop();
        }
        if(cnt==0)
            return time_tmp;
        return -1;
    }
};
// ```