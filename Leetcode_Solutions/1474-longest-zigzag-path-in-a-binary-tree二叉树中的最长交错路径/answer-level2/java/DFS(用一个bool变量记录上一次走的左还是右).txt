执行用时 :5 ms, 在所有 Java 提交中击败了99.76%的用户
内存消耗 :50.5 MB, 在所有 Java 提交中击败了100.00%的用户
### 解题思路
从上往下遍历如果走的方向和上一次一致深度重置，如果不一致就在上一次走的基础上加1。最大深度用全局变量记忆即可。flag为true代表走的左边，为false代表走的右边。
### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    static int depth ;
	public int longestZigZag(TreeNode root) {
		depth = 0 ;
		if(root.left!=null) dfs(root.left,true,1) ;
		if(root.right!=null) dfs(root.right,false,1) ;
		return depth ;
    }
	public void dfs(TreeNode root,boolean flag,int d) {
		if(d>depth)
			depth = d ;
		if(root.left!=null)
		{
			int nd = d+1 ;
			if(flag)
			{
				nd = 1 ;
			}
			dfs(root.left,true,nd) ;
		}
		if(root.right!=null)
		{
			int nd = d+1 ;
			if(!flag)
			{
				nd = 1 ;
			}
			dfs(root.right,false,nd) ;
		}
	}
}
```