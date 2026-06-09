类似于 [岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)


### 代码

```cpp
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int row = land.size();
        if(row==0) return {0};

        int col = land[0].size();
        
        queue<pair<int,int>> bfs_queue;
        vector<int> res;

        int dx[] = {1,1,1,0,0,-1,-1,-1};
        int dy[] = {1,0,-1,1,-1,1,0,-1};

        vector<vector<bool>> visited(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(land[i][j] != 0 || visited[i][j]) continue;

                bfs_queue.push({i,j});
                visited[i][j] = true;
                int cur_area = 1;
                while(!bfs_queue.empty()){
                    auto cur_pos = bfs_queue.front();
                    bfs_queue.pop();
                    
                    for(int i=0;i<8;i++){
                        int new_x = cur_pos.first + dx[i];
                        int new_y = cur_pos.second + dy[i];
                        if(is_valid(row,col,new_x,new_y) && !visited[new_x][new_y] && land[new_x][new_y]==0){
                            bfs_queue.push({new_x,new_y});
                            visited[new_x][new_y] = true;
                            cur_area++;
                            ///cout<<new_x<<" "<<new_y<<endl;
                        }
                    }
                }
                //cout<<cur_area<<endl;
                res.push_back(cur_area);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
    bool is_valid(int row,int col,int new_x,int new_y){
        return new_x>=0 &&  new_x < row && new_y >=0 && new_y < col;
    }
};


 
```