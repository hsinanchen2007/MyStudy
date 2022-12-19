### 解题思路
多源广度优先遍历，思路大体是，
每一轮所有岸边陆地向四周的有水的方格扩展并填充为陆地，并将其加入下一轮的岸边陆地中
每经过一轮岸边扩展，dis++,检查watercount水方格是否有剩余，有则继续，无则返回dis

具体实现看代码注释

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        // dx,dy为辅助用数组
		int[] dx = new int[] {-1,0,1,0};
		int[] dy = new int[] {0,-1,0,1}; 
		//land为岸边陆地队列，采用了使用一个整数存储二维数组位置的方法	
		//存入时， x*n + y;
		//取出时， x = loc/n; y = loc%n; 
		Queue<Integer> land = new LinkedList<Integer>();
		int n = grid.length;
		//watercount为水方格的数量，先预定为n*n,即全部都是水
		int watercount = n*n;
		//首次遍历，找出第一批岸边陆地方格，并计算水方格数量
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					watercount--;
					if ((i - 1 >= 0 && grid[i - 1][j] == 0) || 
						(i + 1 < n && grid[i + 1][j] == 0)|| 
						(j - 1 >= 0 && grid[i][j - 1] == 0) || 
						(j + 1 < n && grid[i][j + 1] == 0)) {
						land.add(i * n + j);
					}
				}
			}
		}
		//若全是水或陆地则返回-1
        if(watercount == n * n || watercount == 0)return -1;
		//dis为扩展轮数，也是最大距离
		int dis = 0;
		while(watercount >= 1) {
			//本轮扩展的岸边陆地的数量
			int landcount = land.size();
			while(landcount-- != 0) {
				//取出坐标
				int landloc = land.poll();
				int x = landloc / n;
				int y = landloc % n;
				//尝试扩展
				for(int i = 0; i < 4; i++) {
					int tx = x + dx[i];
					int ty = y + dy[i];
					if(tx >= 0 && tx < n && 
					   ty >= 0 && ty < n && 
					   grid[tx][ty] == 0) {
						//扩展后，减少水方格，将其扩展陆地加入下一轮的扩展中
						grid[tx][ty] = 1;
						watercount --;
						land.add(tx * n + ty);
					}
				}
			}
			dis++;
		}
		return dis;


    }
}
```