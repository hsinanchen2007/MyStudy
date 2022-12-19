### 解题思路
简单方法用到极限就是快

### 代码

```java
class XY{
	int x;
	int y;
	
	public XY(int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public boolean equals(Object obj) {
		XY xy=(XY) obj;
		return this.x==xy.x&&this.y==xy.y;
	}
	@Override
	public int hashCode() {
		return 1;
	}
}
class Solution {
  //腐烂的橘子
	public int orangesRotting(int[][] grid) {
		Queue<XY> queue=new LinkedList<>();
		int to=0,so=0,numof1=0;
		for(int i=0;i<grid.length;i++) {
			for(int j=0;j<grid[i].length;j++) {
				if(grid[i][j]==1) {
					numof1++;
				}else if(grid[i][j]==2) {
					to++;
					queue.add(new XY(i,j));
				}
			}
		}
		if(numof1==0)return 0;
		int minute=0;
		int numOf1To2=0;
		while(!queue.isEmpty()) {
			int x=0,y=0;
			XY cur = queue.poll();
			to--;
			//north
			x=cur.x-1;
			y=cur.y;
			if(judgeXYInGrid(grid, x, y)&&grid[x][y]==1) {
				grid[x][y]=2;
				queue.add(new XY(x, y));
				++so;
			}
			//south
			x=cur.x+1;
			if(judgeXYInGrid(grid, x, y)&&grid[x][y]==1) {
				grid[x][y]=2;
				queue.add(new XY(x, y));
				++so;
			}
			//west
			x=cur.x;
			y=cur.y-1;
			if(judgeXYInGrid(grid, x, y)&&grid[x][y]==1) {
				grid[x][y]=2;
				queue.add(new XY(x, y));
				++so;
			}
			//east
			y=cur.y+1;
			if(judgeXYInGrid(grid, x, y)&&grid[x][y]==1) {
				grid[x][y]=2;
				queue.add(new XY(x, y));
				++so;
			}
			if(to==0) {
				numOf1To2+=so;
				//第一次grid中所有的2都使用了一次，并且是有1的基础上
				minute++;
				if(numOf1To2==numof1)return minute;
				to=so;
				so=0;
			}	
		}
		return -1;
	}
	private boolean judgeXYInGrid(int[][] grid,int x,int y) {
		return x>=0&&y>=0&&x<grid.length&&y<grid[0].length;
	}
}
```