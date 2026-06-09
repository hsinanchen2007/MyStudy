### 解题思路
此处撰写解题思路

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
		if (root == null)
			return null;
		if (root.left == null && root.right == null)
			return root;
		TreeNode newroot = root;
		LinkedList<TreeNode> treeNodeList = new LinkedList<>();// 用于层次遍历和构造二叉树
		LinkedList<TreeNode> tnd = new LinkedList<>();// 保存遍历结果
		treeNodeList.add(root);
		while (!treeNodeList.isEmpty()) {// 从右子树开始层次遍历二叉树
			TreeNode tem = treeNodeList.removeFirst();
			/**
			 * 尝试写成如下形式时，时间从0ms变为1ms...尴尬
			 * if (tem.right != null) 
			 * 		treeNodeList.add(tem.right); 
			 * tnd.add(tem.right);
			 */
			if (tem.right != null) {
				treeNodeList.add(tem.right);
				tnd.add(tem.right);
			} else
				tnd.add(null);
			if (tem.left != null) {
				treeNodeList.add(tem.left);
				tnd.add(tem.left);
			} else
				tnd.add(null);
		}
		treeNodeList.add(newroot);// 重新构建二叉树
		while (!treeNodeList.isEmpty()) {
			TreeNode node = treeNodeList.removeFirst();
			if (!tnd.isEmpty() && node != null) {
				node.left = tnd.removeFirst();
				treeNodeList.add(node.left);
			}
			if (!tnd.isEmpty() && node != null) {
				node.right = tnd.removeFirst();
				treeNodeList.add(node.right);
			}
		}
		return newroot;
	}
}
```