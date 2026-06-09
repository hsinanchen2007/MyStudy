### 解题思路
如下

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
    	int[]dx= {0,0,1,-1};
    	int[]dy= {1,-1,0,0};   //建立四个方向
    	
    	Queue<int[]>queue=new ArrayDeque<>();    //建立新队列
    	int m  =grid.length, n=grid[0].length;
    	//先把所有陆地入队
    	for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j]==1) {
					queue.offer(new int[] {i,j});
				}
			}
		}
    	
    	//从各个陆地开始，一圈一圈地遍历海洋，最后遍历到的海洋就是离陆地最远的海洋
    	boolean hasOcean=false;
    	int[]point=null;
    	while (!queue.isEmpty()) {
			point =queue.poll();    //建立空数列接收queue里面返回的陆地
			int x = point[0], y=point[1];
			//将取出队列的元素的四周的海洋入队
			for (int i = 0; i < 4; i++) {
				int newX = x+dx[i];
				int newY = y+dy[i];
				if (newX<0||newX>=m||newY<0||newY>=n||grid[newX][newY]!=0) {  //当超出范围或者不为海洋时跳过
					continue;
				}
				//在原数组的基础上进行了更新，对访问过的海洋进行了标记
				grid[newX][newY]=grid[x][y]+1; 
				hasOcean = true;
				queue.offer(new int[] {newX,newY});  //将新找到的海洋入队
			}
			
		}
    	//没有陆地或者没有海洋，返回-1
    	if (!hasOcean||point==null) {
			return -1;
		}
    	//返回最后一次遍历到的海洋的距离
    	return grid[point[0]][point[1]]-1;
    }
}
```