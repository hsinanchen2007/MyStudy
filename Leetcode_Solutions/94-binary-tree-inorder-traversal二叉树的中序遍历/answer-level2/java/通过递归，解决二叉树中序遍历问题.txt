### 解题思路
通过递归遍历方法，首先二叉树的中序遍历：
1、先遍历左子树，记录遍历过程中访问节点的值，形成List返回，并加入到结果List中。
2、遍历根节点，并记录，形成List返回，加入到结果List中。
3、遍历右子树，并记录，形成List返回，并加入到结果List中。
4、发挥结果List。

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
    public List<Integer> inorderTraversal(TreeNode root) {
        LinkedList<Integer> lst= new LinkedList<Integer>();
		 
		if(root!=null) {
			 
			 if(root.left!=null) {
				lst.addAll(inorderTraversal(root.left));
			 }
			 lst.add(root.val);
			 if(root.right!=null) {
				lst.addAll(inorderTraversal(root.right));
			 }			 
		 }
		return lst; 
    }
}
```