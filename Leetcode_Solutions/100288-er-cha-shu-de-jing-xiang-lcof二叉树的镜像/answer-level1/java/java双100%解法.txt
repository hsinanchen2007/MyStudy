### 解题思路
先交换当前节点的值，然后再递归交换左节点和右节点的值

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
    public TreeNode mirrorTree(TreeNode root) {
        TreeNode temp;
	    if(root==null)
	    {
		  return null;
	    }
		temp=root.left;
		root.left=root.right;
		root.right=temp;
		
		mirrorTree(root.left);
		mirrorTree(root.right);
		
		return root;
		}
}
```