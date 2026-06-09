深度优先搜索：定义一个求4个方向面积的函数
```
//深度优先搜索DFS：递归
class Solution {
	/*求解(i,j)的4个方向上的面积，不含(i,j)
	 *如果4个方向都为0，则返回0；若有一个结点为1，flag++，递归的求该结点的旁面积
	 *flag表示的是与(i,j)直接接壤的值为1的结点数*/
	int subfunc(int i,int j,vector<vector<int>>& grid){
        int row=grid.size(),col=grid[0].size();
		int flag=0;
		int m=0;
		int dh[]={0,1,0,-1}; //横向
        int dz[]={-1,0,1,0}; //纵向        //上右下左
		for(int k=0;k<4;k++){
			int x=i+dz[k];
			int y=j+dh[k];
			if(x>=0 && x<row && y>=0 &&y<col && grid[x][y]==1) {
				flag++;
                grid[x][y]=0;
				m+=subfunc(x,y,grid);
			}
		}
		return m+flag;
	}
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
		int res=0;
		int row=grid.size(),col=grid[0].size();
		
		/*对每一个值为1的结点，DFS它的面积*/
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(grid[i][j]==1){
					int temp=1;
					grid[i][j]=0;
					/*subfunc求解(i,j)的4个方向的面积，不含(i,j)*/
					temp+=subfunc(i,j,grid);      
					res=max(res,temp);
				}
			}
		}
		return res;
    }
};
```
广度优先搜索：
```
//广度优先搜索BFS
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        int dh[]={0,1,0,-1}; //横向
        int dz[]={-1,0,1,0}; //纵向        //上右下左
        queue<pair<int,int>> q;

        int res=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    int temp_res=1;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int,int> p=q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int x=p.first+dz[k];  //纵
                            int y=p.second+dh[k]; //横
                            if( x>=0 &&x<row && y>=0 &&y<col && grid[x][y]==1){
                                q.push({x,y});
                                temp_res++;
                                grid[x][y]=0;
                            }
                        }
                    }
                    res=max(res,temp_res);
                }
            }
        }
        return res;
    }
};
```

