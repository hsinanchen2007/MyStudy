### 解题思路
用层次遍历的方式将树的节点存进一个队列，再逐个取出判断左右子树的高度差

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
    public boolean isBalanced(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
		if(root == null) return true;
		queue.add(root);
		TreeNode node;
		while(queue.size() != 0) {
			node = queue.poll();
			int leftHeight = node.left == null ? 0 : getHeight(node.left);
			int rightHeight = node.right == null ? 0 : getHeight(node.right);
			if(Math.abs(leftHeight-rightHeight) >=2) {
				return false;
			}
			if(node.left != null) queue.add(node.left);
			if(node.right != null) queue.add(node.right);
		}
		return true;
    }
    private int getHeight(TreeNode node) {
		int result = 0;
		if(node.left == null && node.right == null) {
			result = 1;
		}else if(node.left == null && node.right != null){
			result = 1 + getHeight(node.right);
		}else if(node.right == null && node.left != null) {
			result = 1 + getHeight(node.left);
		}else {
			result = 1 + Math.max(getHeight(node.left), getHeight(node.right));
		}
		return result;
	}
}
```