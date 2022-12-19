### 解题思路
广度优先搜索，耗内存较少

### 代码

```cpp
class Solution {
private:
    int m_dx[8] = {1,1,1,0,0,-1,-1,-1};
    int m_dy[8] = {1,0,-1,1,-1,1,0,-1};
    int m_row;
    int m_col;
    bool is_valid(int new_x,int new_y){
        return new_x>=0 &&  new_x < m_row && new_y >=0 && new_y < m_col;
    }

    int count_neighbor_mine(int x,int y,vector<vector<char>>& board){
        int cnt = 0;
        for(int i=0;i<8;i++){
            int new_x = x + m_dx[i];
            int new_y = y + m_dy[i];
            if(is_valid(new_x, new_y) && board[new_x][new_y] == 'M'){
                cnt++;
            }
        }
        return cnt;
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int dx[] = {1,1,1,0,0,-1,-1,-1};
        int dy[] = {1,0,-1,1,-1,1,0,-1};
        //直接被挖出
        if(board[click[0]][click[1]] == 'M' ){
            board[click[0]][click[1]] = 'X' ;
            return board;
        }
        m_row = board.size();
        m_col = board[0].size();
    
        //先判断特例
        int clk_x = click[0];
        int clk_y = click[1];
        //计算click周围雷的数量
        int clk_neigh_cnt = count_neighbor_mine(clk_x, clk_y,board);
        
        if(clk_neigh_cnt >0){
            //cout<<clk_neigh_cnt<<endl;
            board[clk_x][clk_y] = '0' + clk_neigh_cnt;
            return board;
        }

        //click周围没有雷，广度优先搜索周围没有雷的坐标
        queue<pair<int,int>> bfs_queue;
        bfs_queue.push({clk_x,clk_y});
        board[clk_x][clk_y] = 'B';
       
        while(!bfs_queue.empty()){
            auto cur_pos = bfs_queue.front();
            bfs_queue.pop();
            int cur_x = cur_pos.first,cur_y = cur_pos.second;
            for(int i=0;i<8;i++){
                int new_x = cur_x + dx[i];
                int new_y = cur_y + dy[i];
                if(!is_valid(new_x, new_y) ) continue;
                int cnt = count_neighbor_mine(new_x, new_y, board);
                
                if(cnt >0){
                    board[new_x][new_y] = '0' + cnt;
                }else if(board[new_x][new_y] == 'E'){
                    board[new_x][new_y] = 'B';
                    bfs_queue.push({new_x,new_y});
                }
            }
        }

        return board;


    }
};
```
## 结果

![image.png](https://pic.leetcode-cn.com/c790a706eb4fb599658ae14ce58dc481b83ecc55de40801ff39d9fa6494cebdc-image.png)
