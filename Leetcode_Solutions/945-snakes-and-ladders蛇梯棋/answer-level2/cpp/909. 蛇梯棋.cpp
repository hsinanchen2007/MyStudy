
先吐槽一下，这道题的中文翻译真的是捉急……棋盘上每次移动是掷骰子决定的，每次移动的范围是$[x+1, x+6]$。将编号映射到棋盘坐标，以编号为状态进行BFS，注意处理蛇或梯子即可。

```c++ []
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        N = board.size();
        
        //映射坐标
        getId2Pos(board);
        
        queue<Pair> que;
        vector<bool> vis(N*N+1, false);
        int total = numeric_limits<int>::max();
        
        que.push(Pair(1, 0));
        while(que.size()){
            auto now = que.front();
            que.pop();
            
            //更新最小值
            if(now.first == N*N && total > now.second)total = now.second;
            
            if(vis[now.first]) continue;
            vis[now.first] = true;
            
            for(int i = 1;i <= 6;i++){
                
                //获取下一个编号
                int next_id = now.first + i;
                
                if(next_id > N * N) continue;
                
                int nx = id2pos[next_id].first;
                int ny = id2pos[next_id].second;
                
                //判断如何行走
                if(board[nx][ny] > 0){
                    que.push(Pair(board[nx][ny], now.second+1));
                }else{
                    que.push(Pair(next_id, now.second+1));
                }
            }
        }
        
        return total == numeric_limits<int>::max() ? -1 : total ;
    }
private:
    using Pair = pair<int, int>;
    vector<Pair> id2pos;
    int N;
    
    // 将编号映射到棋盘坐标
    void getId2Pos(vector<vector<int>>& board){
        id2pos.resize(N*N+1);
        
        bool travel_reverse = true;
        int curr = 1;
        for(auto i = N-1;i >= 0;--i){
            if(travel_reverse){
                for(auto j = 0;j < N;++j){
                    id2pos[curr++] = Pair(i,j);
                }
                travel_reverse = false;
            }else{
                for(auto j = N-1;j >= 0;--j){
                    id2pos[curr++] = Pair(i,j);
                }
                travel_reverse = true;
            }
        }
        return;
    }
};
```