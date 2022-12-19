执行时间 44ms，直接上代码。
```
class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int res=0;
        for(int i = 0;i<A[0].size();i++){
            if(A[0][i]==1)dfs(A,0,i);
            if(A[A.size()-1][i]==1)dfs(A,A.size()-1,i);

        }
        for(int i = 0;i<A.size();i++){
            if(A[i][0]==1)dfs(A,i,0);
            if(A[i][A[0].size()-1]==1)dfs(A,i,A[0].size()-1);
        }

        for(auto i:A){
            for(auto j:i)
              res+=j;
        }
        return res;
        
    }
    void dfs(vector<vector<int>>& A,int i,int j){
        if(0>i||i>=A.size()||0>j||j>=A[0].size()||A[i][j]==0)return;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        A[i][j]=0;
        for(int n=0;n<4;n++){
            int x=i+dx[n];
            int y=j+dy[n];
            dfs(A,x,y);
        }
    }
};
```
开始时候是想使用queue与pair两个嵌套，使用不过一直超时，后面修改还是老老实实使用递归比较省时间吧。附之前超时代码
```
class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int res=0;
        for(int i = 0;i<A[0].size();i++){
            if(A[0][i]==1)dfs(A,0,i);
            if(A[A.size()-1][i]==1)dfs(A,A.size()-1,i);

        }
        for(int i = 0;i<A.size();i++){
            if(A[i][0]==1)dfs(A,i,0);
            if(A[i][A[0].size()-1]==1)dfs(A,i,A[0].size()-1);
        }

        for(auto i:A){
            for(auto j:i)
              res+=j;
        }
        return res;
        
    }
    void dfs(vector<vector<int>>& A,int i,int j){
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        queue<pair<int,int>> qu;
        qu.emplace(pair<int,int>(i,j));

         while(!qu.empty()){
            pair<int,int>temp = qu.front();
            qu.pop();
            A[temp.first][temp.second]=0;
            for(int i=0;i<4;i++){
                int x=temp.first+dx[i];
                int y=temp.second+dy[i];
                if(0<=x&&x<A.size()&&0<=y&&y<A[0].size()&&A[x][y]==1){
                    qu.emplace(pair<int,int>(x,y));
                }
            }
        }
        
    }
};
```

