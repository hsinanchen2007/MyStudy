### 解题思路
此处撰写解题思路
个人认为这道题目比较综合，能较好检验个人代码能力，因为考察的知识点不少，以及实现的能力。
1. 首先是广度优先，需要使用队列，这个已经是老生常谈了；
2. 重要的是如何计算这个时间，因为没法定义时间这个变量，这里很巧妙地运用了HashMap，将位置与时间作为键值对，当前取值为上一阶段腐烂所需要的时间加1，非常巧妙。事先将开局已经腐烂的橘子加入队列中，并设置计时为0。
3. 当队列为空后，判断是否还有新鲜的橘子。
4. 具体见代码。
### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
		int row = grid.length;
		if (row==0) return 0;
		int col = grid[0].length;
		HashMap<Integer, Integer> map = new HashMap<>();
		int[] ii = {1,-1,0,0};
		int[] jj = {0,0,1,-1};
		int time = 0;
		Queue<Integer> q_i = new ArrayDeque<>(); // 存储横坐标
		Queue<Integer> q_j = new ArrayDeque<>(); // 存储纵坐标
		// 将初始腐烂的橘子放入HashMap中，其键表示位置，值表示发生腐烂的时间。
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				if (grid[i][j]==2) {
					int code = i * col + j;
					map.put(code, 0);
					q_i.offer(i);
					q_j.offer(j);
				}
			}
		}
		while (!q_i.isEmpty()) {
			int cur_i = q_i.poll();
			int cur_j = q_j.poll();
			int code = cur_i * col + cur_j;
			for (int k=0; k<4; k++) {
				int tem_i = cur_i + ii[k];
				int tem_j = cur_j + jj[k];
				if (tem_i>=0 && tem_i<row && tem_j>=0 && tem_j<col && grid[tem_i][tem_j]==1) {
					grid[tem_i][tem_j] = 2;
					int ncode = tem_i * col + tem_j;
					map.put(ncode, map.get(code)+1);
					q_i.offer(tem_i);
					q_j.offer(tem_j);
					time = map.get(ncode);
				}
			}
		}
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				if (grid[i][j] == 1) return -1; 
			}
		}
		return time;
    }
}
```