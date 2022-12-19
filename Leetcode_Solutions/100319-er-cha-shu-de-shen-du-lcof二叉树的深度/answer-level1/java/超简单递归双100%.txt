### 解题思路
> **一种思路**：
如果一棵树只有一个根节点，则深度为1；
如果只有左子树，深度应为左子树深度+1；
如果只有右子树，深度应为右子树深度+1；
如果既有左子树又有右子树，深度应为两者较大的深度+1。

> 基于这种思路可以用**递归**实现。

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
    public int maxDepth(TreeNode root) {
        if(root==null)
			return 0;
		int nLeft = maxDepth(root.left);
		int nRight=maxDepth(root.right);
		
		return (nLeft>nRight)? (nLeft+1):(nRight+1);
    }
}
```