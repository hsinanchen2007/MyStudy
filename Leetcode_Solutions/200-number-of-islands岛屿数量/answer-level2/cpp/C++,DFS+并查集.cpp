DFS：
```
//疑问：主函数写成这样就会出现RTE
int numIslands(vector<vector<char>>& grid) {
    int n=grid.size();//这样写为什么会出错，很是不解？？？？
    int m=grid[0].size();
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                dfs(grid,i,j);
                res++;
            }
        }
    }
}
```

```
class Solution {
public:
    
    void dfs(vector<vector<char>>& grid,int x,int y){//目的是将加入的岛屿，重新赋值成0,就不是原来岛屿的标记
            // int dx[4]={-1,0,1,0};
            // int dy[4]={0,1,0,-1};
            // grid[x][y]='0';//遍历完成之后，设置成0
            // for(int i=0;i<4;i++){
            //     int a=x+dx[i];
            //     int b=y+dy[i];
            //     if(a>=0&&a<n&&b>=0&&b<m&&grid[a][b]=='1'){
            //         dfs(grid,a,b);
            // }
            if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||grid[x][y]=='0')return;
            grid[x][y]='0';
            dfs(grid,x-1,y);
            dfs(grid,x+1,y);
            dfs(grid,x,y-1);
            dfs(grid,x,y+1);   
        }
    int numIslands(vector<vector<char>>& grid) {
        // int n,m;
        // n=grid.size();//我就非常
        // m=grid[0].size();
       // if(n==0)return 0;
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    //res++;
                    dfs(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }

        
};
```
方法二：
并查集：
```
//vector<int>father;
const int maxn=0x7f7f7f;
int father[maxn];
//并查集
class Solution {
public:

    int find(int i){
        while(father[i]!=i){
            i=father[i];
        }
        return i;
    }
    void uni(int i,int j){
        int f1=find(i);
        int f2=find(j);
        father[f2]=f1;
    }
    int numIslands(vector<vector<char>>& grid) {
        //int m=grid.size();
        //int n=grid[0].size();
        if(grid.size()==0||grid[0].size()==0)return 0;
        //初始化
        
        for(int i=0;i<grid[0].size()*grid.size();i++){
            father[i]=i;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    int cur=i*grid[0].size()+j;
                    if(i>0&&grid[i-1][j]=='1')uni(cur,cur-grid[0].size());
                    if(i<grid.size()-1&&grid[i+1][j]=='1')uni(cur,cur+grid[0].size());
                    if(j>0&&grid[i][j-1]=='1')uni(cur,cur-1);
                    if(j<grid[0].size()-1&&grid[i][j+1]=='1')uni(cur,cur+1);
                }
            }
        }
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int cur=i*grid[0].size()+j;
                if(father[cur]==cur&&grid[i][j]=='1')count++;
            }
        }
        // for(int i=0;i<m*n;i++){
        //     if(father[i]==i)count++;
        // }
        return count;
    }
};
```
