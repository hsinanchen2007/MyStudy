### 解题思路
按照 [大力王](https://leetcode-cn.com/u/da-li-wang/) 的c++ 思路改为 java 

### 参考
[大力王 c++ 思路](https://leetcode-cn.com/problems/shortest-path-with-alternating-colors/solution/c-shen-du-you-xian-sou-suo-by-da-li-wang-4/)

### 代码

```java
class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] red_edges, int[][] blue_edges) {
		List<List<Integer>> rg = new ArrayList<>();//这是 红色线的集合
		List<List<Integer>> bg = new ArrayList<>();//这是 蓝色线的集合

		for (int i = 0; i < n; i++) {
			//初始化两条线的集合
			rg.add(new ArrayList<>());
			bg.add(new ArrayList<>());
		}

		//根据数组改变 红蓝色线 集合
		for (int[] red : red_edges)rg.get(red[0]).add(red[1]);
		for (int[] blue : blue_edges)bg.get(blue[0]).add(blue[1]);

		int[][] ans = new int[n][2];
		for (int[] ansColor : ans) {
			//初始化所有距离为MAX
			ansColor[0] = Integer.MAX_VALUE;
			ansColor[1] = Integer.MAX_VALUE;
		}
		//出发点距离设为0
		ans[0][0] = 0;
		ans[0][1] = 0;

		dfs(ans, 0, 0, rg, bg);//从红色线出发
		dfs(ans, 1, 0, rg, bg);//从蓝色线出发

		int[] finalAns = new int[n];
		for (int i = 0; i < n; i++) {
			//取最小值  没有的话为-1
			finalAns[i] = Math.min(ans[i][0], ans[i][1]);
			if (finalAns[i] == Integer.MAX_VALUE)
				finalAns[i] = -1;
		}
		return finalAns;
	}

	public void dfs(int[][] ans, int color, int i, List<List<Integer>> rg, List<List<Integer>> bg) {
		List<List<Integer>> g = color == 0 ? rg : bg;//选择 红蓝色 线
		for (int j : g.get(i)) {
			//遍历该线段 以 i 为出发点的终点

			if (ans[i][color] + 1 < ans[j][Math.abs(color - 1)]) {
				//判断 0 -> i -> j 的长度是否 比 已有的 0 -> j 的路径长度长 若是 则更新 
				//!!!这个判断是整个算法的核心 
				//当在也找不到更短的路径时 dfs会停止搜索 否则继续

				ans[j][Math.abs(color - 1)] = ans[i][color] + 1;
				dfs(ans, Math.abs(color - 1), j, rg, bg);
			}
		}
	}
}
```