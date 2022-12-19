### 解题思路
dfs遍历所有的可能。
### 代码

```java
class Solution {

    static int[][] maps;
	static int M;
	static int N;
	static int sx,sy,ex,ey;
	static int total;
	static int[] dx=new int[]{-1,0,1,0};
	static int[] dy=new int[]{0,1,0,-1};
	static boolean[][] visited;

    	public static int uniquePathsIII(int[][] grid) {
		if(grid==null){
			return 0;
		}
		total=0;
		if(grid.length>0){
			maps=grid;
			M=grid.length;
			N=grid[0].length;
			visited=new boolean[M][N];
			for(int i=0;i<M;i++){
				for(int j=0;j<N;j++){
					if(maps[i][j]==1){
						sx=i;
						sy=j;
					}
					if(maps[i][j]==2){
						ex=i;
						ey=j;
					}
				}
			}
			visited[sx][sy]=true;
			dfs(sx,sy);
		}
		return total;
    }
	private static void dfs(int x, int y) {
		if(x==ex&&y==ey){
			if(allVisited()){
				total++;
			}
			return;
		}
		for(int i=0;i<4;i++){
			if(0<=x+dx[i]&&x+dx[i]<M&&y+dy[i]>=0&&y+dy[i]<N){
				if((maps[x+dx[i]][y+dy[i]]==0||maps[x+dx[i]][y+dy[i]]==2)&&!visited[x+dx[i]][y+dy[i]]){
					visited[x+dx[i]][y+dy[i]]=true;
					dfs(x+dx[i],y+dy[i]);
					visited[x+dx[i]][y+dy[i]]=false;
				}
			}else{
				continue;
			}
		}
	}
	private static boolean allVisited(){
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				if(visited[i][j]==false){
					if((i==ex&&j==ey)||maps[i][j]==-1){
					}else{
						return false;
					}
				}
			}
		}
		return true;
	}
}
```