这题比较恶心了一点，确实跟上一题不一样。

1. 刚开始用准备用DFS，结果发现超时，后来改成BFS，但是本题目中的BFS有点特殊，首先进行预处理，得到每个节点的下一跳，通过next数组保存。
2. 因为先到达的路径不一定是最短路径，因为每一跳的路径长短不一样，因此处理较为复杂。
3. 最终的处理，设置一个数组dp[x][y]代表，从起点处到达点（x,y）的最短路径，每次路径经过该节点时，则比较经过的路径distance与dp[x][y]的大小，如果distance比dp[x][y]还小的话，则将该节点加入队列进行下路BFS操作。
4. 到达终点则进行多轮比较。
```BFS []
class Solution {
public:
    
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int r = maze.size();
        int c = maze[0].size();
        int next[100][100][4];
        int d[4][2] = {{0,1},{1,0},{0,1},{1,0}};
        vector<vector<int>> dp(r,vector<int>(c,INT_MAX));
        queue<pair<int,int>> qu;
                
        /*initial*/
        for(int i = 0;i < r; ++i){
            for(int j = 0;j < c; ++j){
                for(int k = 0;k < 4; ++k){
                    next[i][j][k] = -1;
                }
                /*left*/
                for(int k = j-1;k >= 0;--k){
                    if(maze[i][k] == 0){
                        next[i][j][0] = i*c + k;
                    }else{
                        break;
                    }
                }
                /*up*/
                 for(int k = i-1;k >= 0;--k){
                    if(maze[k][j] == 0){
                        next[i][j][1] = k*c + j;
                    }else{
                        break;
                    }
                }
                /*right*/
                for(int k = j+1;k < c;++k){
                    if(maze[i][k] == 0){
                        next[i][j][2] = i*c + k;
                    }else{
                        break;
                    }
                }
                /*down*/
                for(int k = i+1;k < r;++k){
                    if(maze[k][j] == 0){
                        next[i][j][3] = k*c + j;
                    }else{
                        break;
                    }
                }
            }
        }
                
        qu.push(make_pair(start[0]*c+start[1],0));
        dp[start[0]][start[1]] = 0;
        int res = INT_MAX;
        
        while(!qu.empty()){
            pair<int,int> curr = qu.front();
            qu.pop();
            
            int x = curr.first/c;
            int y = curr.first%c;
            int dist = curr.second;
            
            if(x == destination[0] && y == destination[1]){
                res = min(res,dist);
            }
            
            for(int i = 0;i < 4; ++i){
                if(next[x][y][i] != -1){
                    int x1 = next[x][y][i]/c;
                    int y1 = next[x][y][i]%c;
                    int add = abs(x-x1)*d[i][0] + abs(y-y1)*d[i][1];
                    if((dist + add) < dp[x1][y1]){
                        qu.push(make_pair(x1*c+y1,dist+add));
                        dp[x1][y1] = dist+add;
                    }
                }
            }
        }
        
        if(res == INT_MAX){
            return -1;
        }
        
        return res;
    }
};
```
