萌新第二次写题解(0.0)

## 思路
这个题和前几天的找最远的海洋有相似之处，我也是做了那道题之后才学习的广搜。这个题就是从`[0,0]`一个端点出发，只用考虑向右和向下这两个方向。用一个二维数组记录遍历的状态。用一个队列来保存层节点。


## 代码
```
class Solution {
    //用来获取每个位数的和
    public int get(int x) {
		if(x == 0) return 0;
        int res = 0;
		
		for(; x != 0; x = x / 10) {
			res += x % 10;
		}
		
		return res;
	}

    public int movingCount(int m, int n, int k) {
        if(k == 0) return 1;
int ans = 1;
		int[][] grid = new int[m][n];
		//定义右,下方向
		int[] dirX = {1, 0};
		int[] dirY = {0, 1};
		
		//用队列保存该层的遍历节点
		Queue<int[]> q = new ArrayDeque<>();
        //添加[0,0]
		q.offer(new int[] {0, 0});
		grid[0][0] = 1;
		int[] point = null;
		
		while(!q.isEmpty()) {
			point = q.poll();
			int x = point[0];
			int y = point[1];
			//遍历右，下相邻节点
			for(int i = 0; i < dirX.length; i++) {
				int newX = x +  dirX[i];
				int newY = y + dirY[i];
				//不满足条件的话
				if(newX >= m || newY >= n || get(newX) + get(newY) > k || grid[newX][newY] == 1) {
					continue;
				}
				grid[newX][newY] = 1;
				ans += 1;
				q.offer(new int[] {newX, newY});
				
			}
			
		}
		
		return ans;

    }
}
```
