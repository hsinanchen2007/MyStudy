
```java
class Solution {
    /**
	 * 0 unvisited
	 * 1 visited
	 * 2 safe
	 * 3 unsafe
	 */
	static int graph[][];
	static int visit[];
	
	public List<Integer> eventualSafeNodes(int[][] graph) {
		this.graph = graph;
		List<Integer> ans = new ArrayList<Integer>();
		int len = graph.length;
		visit = new int [len];
		for (int i = 0; i < len; i++) {
			if(dfs(i) == 2)
				ans.add(i);
		}
		
		
		return ans;
        
    }

	private int dfs(int i) {
		if(visit[i] == 1)
			return 3;
		if(visit[i]!=0)
			return visit[i];
		visit[i] = 1;
		for (int j = 0; graph[i] !=null && j < graph[i].length; j++) {
			if(dfs(graph[i][j]) == 3) {
				visit[i] = 3;
				return 3;
			}
				
		}
		visit[i] = 2;
		return 2;
	}

}
```
