### 代码

```java
class Solution {
    int count = 0;
	public int movingCount(int m,int n,int k){
		// 广度优先搜索，维护一个m*n的isVisited数组，记录访问过的格子
		// 注意：1 <= n,m <= 100
		int[][] isVisited = new int[m][n];
		bfs(0,0,isVisited,k);
		return count;
	}
	
	public void bfs(int row,int col,int[][] isVisited,int k){
		if(row >=0 && row<isVisited.length && col>=0 && col<isVisited[0].length && isVisited[row][col] == 0){
			// 再判断是否符合题设条件
			if(isValid(row,col,k)){
				count++;
				isVisited[row][col] = 1;
				int[] x = {-1,1,0,0};
				int[] y = {0,0,-1,1};
				int newRow;
				int newCol;
				for(int i=0;i<4;i++){
					newRow = row + x[i];
					newCol = col + y[i];
					bfs(newRow,newCol,isVisited,k);
				}
			}
		}
	}
	
	public boolean isValid(int newRow,int newCol,int k){
		int rowPos1 = newRow/100;
		int rowPos2 = (newRow-rowPos1*100)/10;
		int rowPos3 = newRow-rowPos1*100-rowPos2*10;
		int colPos1 = newCol/100;
		int colPos2 = (newCol-colPos1*100)/10;
		int colPos3 = newCol-colPos1*100-colPos2*10;
		if((rowPos1+rowPos2+rowPos3+colPos1+colPos2+colPos3) <= k){
			return true;
		}
		return false;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/c3e71a150e6db96b702948ccda69ef0e8311cafdae0e5f5772964e9f8c90c7a5-1.png)
