### 解题思路
广度优先遍历 ==> 用于求最短路径问题  --> 
没有新鲜橘子所经过的最小分钟数--> 求腐烂橘子道所有新鲜橘子的最短路径
（上下左右新鲜橘子就是腐烂橘子的同一层）
用队列来做 ( 进队-->隔离区 腐烂的橘子--> 污染区  一个传染上下左右四个)
1.找到腐烂的橘子，入队列queue，记录新鲜的橘子count
2.当队列不为空，count不为空时，开始进行广度优先遍历
 腐烂橘子上下左右分别遍历，新鲜，则腐烂，round++，count--
3.最终，count>0 返回-1 否则返回round

### 代码
`#python
class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        M = len(grid)   # grid的行数
        N = len(grid[0])  # grid的列数
        queue = []
        count = 0  # count表示新鲜橘子的数量
        for r in range(M):
            for c in range(N):
                if grid[r][c] == 1:  # 是新鲜的橘子
                    count+=1
                elif grid[r][c] == 2:  # 腐烂的橘子入队
                    queue.append((r,c))

# 进行广度优先遍历  上下左右腐烂
        round = 0 # round 表示腐烂的轮数或者分钟数
        while count > 0 and len(queue) > 0:  # 新鲜橘子不为空，队列也不为空时循环
            round += 1  # 进行下一轮
            n = len(queue)   # 队列里的橘子
            for i in range(n):
                r,c = queue.pop(0)  # 拿出队头的橘子
                if r-1 >= 0 and grid[r-1][c] == 1:  # 上，新鲜-->腐烂
                    grid[r-1][c] = 2
                    count-=1
                    queue.append((r-1,c))
                if r + 1 < M and grid[r + 1][c] == 1:
                    grid[r + 1][c] = 2
                    count -= 1
                    queue.append((r + 1, c))
                if c - 1 >= 0 and grid[r][c - 1] == 1:  # 左
                    grid[r][c - 1] = 2
                    count -= 1
                    queue.append((r, c - 1))
                if c + 1 < N and grid[r][c + 1] == 1:  # 右
                    grid[r][c + 1] = 2
                    count -= 1
                    queue.append((r, c + 1))
        if count > 0:
            return  -1
        else:
            return  round


`
```java
class Solution {
    public int orangesRotting(int[][] grid) {
		int m = grid.length;
		int n = grid[0].length;
		Queue<int[]>queue = new LinkedList<>();
		int count =0;
		for (int r=0;r<m;r++) {
			for(int c=0;c<n;c++) {
				if (grid[r][c] == 1) {
					count+=1;	
				}
				else if(grid[r][c]==2) {
					queue.offer(new int[] {r,c});
				}
			}
		}
		 int round = 0;
		 while( !queue.isEmpty() && count>0) {
			 round++;
			 int l = queue.size();
			 for(int i=0;i<l;i++) {
				 int[] orange = queue.poll();
				 int r = orange[0];
				 int c = orange[1];
				 if (r-1>=0 && grid[r-1][c]==1) {
					 grid[r-1][c]=2;
					 count--;
					 queue.offer(new int[] {r-1,c});
				 }
				 if (r+1<m && grid[r+1][c]==1) {
					 grid[r+1][c]=2;
					 count--;
					 queue.offer(new int[] {r+1,c});
				 }
				 if (c-1>=0 && grid[r][c-1]==1) {
					 grid[r][c-1]=2;
					 count--;
					 queue.offer(new int[] {r,c-1});
			 }
				 if (c+1 < n && grid[r][c+1]==1) {
					 grid[r][c+1]=2;
					 count--;
					 queue.offer(new int[] {r,c+1});
		 }		
	}
		 }
		 if(count>0) return -1;
		 else {
			 return round;
		 }
	}
	
	
}


```