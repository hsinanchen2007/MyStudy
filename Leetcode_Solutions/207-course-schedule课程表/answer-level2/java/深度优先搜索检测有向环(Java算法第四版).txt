
思路：在深度优先遍历有向图时，一旦我们找到了一条有向边v->w且w已经存在于栈中，就找到了一个环，因为栈表示的是一条由w到v的有向路径，而v->w正好补全了这个环。我们用数组onStack标记已经在栈中的顶点。

```
class Solution 
{
	private boolean[] marked;
	private ArrayList<Integer>[] adj; //邻接表
	private boolean[] onStack; //标记已经在栈中的顶点
	private boolean hasCycle = false;
		
	public boolean canFinish(int numCourses, int[][] prerequisites) 
	{
		marked = new boolean[numCourses];
		onStack = new boolean[numCourses];
		adj = (ArrayList<Integer>[]) new ArrayList[numCourses];
		for (int i = 0; i < numCourses; i++)
		{
			adj[i] = new ArrayList<Integer>();
		}
		
		//将有向边加入邻接表
		for (int[] row : prerequisites)
		{
			adj[row[1]].add(row[0]);
		}
		
		for (int s = 0; s < numCourses; s++)
		{
			if (!marked[s]) dfs(s);
		}
		
		return !hasCycle;

	}

	private void dfs(int s)
	{
		onStack[s] = true;
		marked[s] = true;
		for (int w : adj[s])
		{
			if (hasCycle) return;
			else if (!marked[w]) dfs(w);
			else if (onStack[w]) hasCycle = true; //如果w已经在栈中说明找到了一个环
		}
		onStack[s] = false;
	}
}
```
![未命名图片.png](https://pic.leetcode-cn.com/1313595ca484988ca8b2ee030d5d5134601ab09491831a485573b921ee591d63-%E6%9C%AA%E5%91%BD%E5%90%8D%E5%9B%BE%E7%89%87.png)
