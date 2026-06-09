假如这是一条单分支树，那么就是求数组的子数组等于目标值，求目标的子数组，很明显想到前缀和，我们用一个Map<Integer,Integer> count 来记录前缀和相同的数目。

```
    Map<Integer,Integer> count;
	int ans;
	public int pathSum(TreeNode root, int sum) {
		count = new HashMap<>();
		count.put(0, 1);
		dfs(root,0,sum);
		return ans;
    }
	public void dfs(TreeNode node,int sum,int t) {
		if(node!=null) {
			int cur = sum+node.val; 
			if(count.containsKey(cur-t))
				ans+=count.get(cur-t);
			count.put(cur, count.getOrDefault(cur, 0)+1);
			dfs(node.left,cur,t);
			dfs(node.right,cur,t);
			count.put(cur, count.get(cur)-1);
		}
	}
```
