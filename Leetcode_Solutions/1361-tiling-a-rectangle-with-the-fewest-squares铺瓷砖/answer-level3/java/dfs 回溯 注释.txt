### 解题思路


### 代码

```java
class Solution {
    static int total;
	static int result;
	static boolean[][] maps;
	static int num;
	static int min;
    static int M;
	//lie
	static int N;


	public static int tilingRectangle(int n, int m) {
		M=n;
		N=m;
		maps=new boolean[M][N];
		result=99999;
		if(n>m){
			min=m;
		}else{
			min=n;
		}
		dfs(0,0,0);
		return result;
    }
	private static void dfs(int x, int y, int total) {
		if(y==N){
			x++;
			y=0;
		}
		if(x==M){
			if(result>total){
				result=total;
			}
		}
		if(total>=result){
			return;
		}
//如果贴过了的情况
		if(maps[x][y]==true){
			dfs(x,y+1,total);
		}else{
loop:			for(int i=1;i<=min;i++){
				boolean canUse=true;
				for(int k1=0;k1<i;k1++){
					for(int k2=0;k2<i;k2++){
						if(x+k1>=M||y+k2>=N){
							canUse=false;
							break loop;
						}
						if(x+k1<M&&y+k2<N){
							if(maps[x+k1][y+k2]==true){
								canUse=false;
								break loop;
							}
						}
					}
				}
				if(canUse){
					for(int k1=0;k1<i;k1++){
						for(int k2=0;k2<i;k2++){
							num++;
							maps[x+k1][y+k2]=true;
						}
					}
					total++;
					dfs(x,y+i,total);
					total--;
					//回溯
					for(int k1=0;k1<i;k1++){
						for(int k2=0;k2<i;k2++){
							num--;
							maps[x+k1][y+k2]=false;
						}
					}
				}else{
					break;
				}
			}
		}
	}
}
```