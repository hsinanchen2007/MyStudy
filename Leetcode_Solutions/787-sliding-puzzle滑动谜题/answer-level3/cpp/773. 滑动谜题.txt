
一道比较常规的BFS，难点在于状态的定义和转移。因为谜板比较小，所以可以用字符串来表示状态。两个主要操作分别是根据当前状态复原谜板，以及根据移动后的谜板获取状态。

```c++ []
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<Pair> que;
        unordered_map<string, bool> vis;
        
        que.push(Pair(getState(board),0));
        vis[getState(board)] = true;
        
        while(que.size()){
            Pair now = que.front();
            que.pop();
            
            //终止状态
            if(now.first == "123450") return now.second;
            
            //获取当前0的位置，以进行移动
            pair<int, int> pos = getPosFromState(now.first);
            for(int i = 0;i < 4;++i){
                
                int nx = pos.first + dir[i][0];
                int ny = pos.second + dir[i][1];
                
                if(nx < 0 || nx >= bx || ny < 0 || ny >= by)
                    continue;
                
                //获取当前状态下对应的谜板
                vector<vector<int>> tmp = getBoardFromState(now.first);
                
                //移动0
                tmp[pos.first][pos.second] = tmp[nx][ny];
                tmp[nx][ny] = 0;
                
                //移动后的谜板状态
                string tmp_state = getState(tmp);
                
                if(vis[tmp_state]) continue;
                que.push(Pair(tmp_state,now.second+1));
                vis[tmp_state] = true;
            }
        }
        return -1;
    }
private:
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int bx = 2, by = 3;
    using Pair = pair<string, int>;
    
    //根据当前状态返回谜板
    vector<vector<int>> getBoardFromState(string state){
        vector<vector<int>> board(bx, vector<int>(by, 0));
        for(int i = 0;i < bx;++i){
            for(int j = 0;j < by;++j){
                board[i][j] = state[i*by+j] - '0';
            }
        }
        return board;
    }
    
    //根据当前状态返回0的位置
    pair<int,int> getPosFromState(string state){
        int diff = state.find('0');
        pair<int, int> pos;
        switch(diff){
            case 0: {pos = make_pair(0,0);break;}
            case 1: {pos = make_pair(0,1);break;}
            case 2: {pos = make_pair(0,2);break;}
            case 3: {pos = make_pair(1,0);break;}
            case 4: {pos = make_pair(1,1);break;}
            case 5: {pos = make_pair(1,2);break;}
        }
        return pos;
    }
    
    //根据谜板获取当前状态
    string getState(vector<vector<int>>& board){
        string state;
        for(int i = 0;i < bx; ++i){
            for(int j = 0;j < by; ++j){
                state.push_back(board[i][j] + '0');
            }
        }
        return state;
    }
};
```

