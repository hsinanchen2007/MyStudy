利用队列实现BFS
```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=0;
        if(rows==0){
            return 0;
        }else{
            cols=grid[0].size();
        }
        queue<pair<int,int>> Q;
        int nums=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    nums++;
                    Q.push(make_pair(i,j));
                    grid[i][j]='0';
                    while(!Q.empty()){
                        pair<int,int> node=Q.front();
                        Q.pop();
                        if(node.first+1<rows && grid[node.first+1][node.second]=='1'){
                            Q.push(make_pair(node.first+1,node.second));
                            grid[node.first+1][node.second]='0';
                        }
                        if(node.second+1<cols && grid[node.first][node.second+1]=='1'){
                            Q.push(make_pair(node.first,node.second+1));
                            grid[node.first][node.second+1]='0';
                        }
                        if(node.first-1>=0 && grid[node.first-1][node.second]=='1'){
                            Q.push(make_pair(node.first-1,node.second));
                            grid[node.first-1][node.second]='0';
                        }
                        if(node.second-1>=0 && grid[node.first][node.second-1]=='1'){
                            Q.push(make_pair(node.first,node.second-1));
                            grid[node.first][node.second-1]='0';
                        }

                    }                    
                }

            }
        }
        return nums;
    }
};
```
DFS（递归版）:
```
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        int rows=grid.size();
        int cols=0;
        if(rows==0){
            return;
        }else{
            cols=grid[0].size();
        }
        
        if(i+1<rows && grid[i+1][j]=='1'){
            grid[i+1][j]='0';
            dfs(grid,i+1,j);
            
        }
        if(j+1<cols && grid[i][j+1]=='1'){
            grid[i][j+1]='0';
            dfs(grid,i,j+1);
            
        }
        if(i-1>=0 && grid[i-1][j]=='1'){
            grid[i-1][j]='0';
            dfs(grid,i-1,j);
           
        }
        if(j-1>=0 && grid[i][j-1]=='1'){
            grid[i][j-1]='0';
            dfs(grid,i,j-1);
            
        }
        return;
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=0;
        if(rows==0){
            return 0;
        }else{
            cols=grid[0].size();
        }
        int nums=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    nums++;
                    dfs(grid,i,j);                   
                }
            }
        }
        return nums;
    }
};
```

DFS（迭代版）:
```
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        int rows=grid.size();
        int cols=0;
        if(rows==0){
            return;
        }else{
            cols=grid[0].size();
        }
        stack<pair<int,int>> S;
        S.push({i,j});
        grid[i][j]='0';
        while(!S.empty()){
            pair<int,int> node=S.top();
            i=node.first;
            j=node.second;
            S.pop();
            if(i+1<rows && grid[i+1][j]=='1'){
                grid[i+1][j]='0';
                S.push({i+1,j});
            
            }
            if(j+1<cols && grid[i][j+1]=='1'){
                grid[i][j+1]='0';
                S.push({i,j+1});
            
            }
            if(i-1>=0 && grid[i-1][j]=='1'){
                grid[i-1][j]='0';
                S.push({i-1,j});
           
            }
            if(j-1>=0 && grid[i][j-1]=='1'){
                grid[i][j-1]='0';
                S.push({i,j-1});
            
            }
        }

        return;
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=0;
        if(rows==0){
            return 0;
        }else{
            cols=grid[0].size();
        }
        int nums=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    nums++;
                    dfs(grid,i,j);                   
                }
            }
        }
        return nums;
    }
};
```
