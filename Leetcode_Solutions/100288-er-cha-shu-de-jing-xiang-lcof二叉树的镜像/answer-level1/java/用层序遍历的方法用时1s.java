### 解题思路
首先实现二叉树层序遍历，维护一个队列，在遍历过程中，把每层中两两相对应的左右子树互换就生成镜像二叉树

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
		TreeNode res = root;
		if (root != null) {
			Queue<TreeNode> que = new LinkedList<>();
			que.offer(root);
			while (!que.isEmpty()) {
				root = que.poll();
				TreeNode temp = null;
				temp = root.right;
				root.right = root.left;
				root.left = temp;
				if (root.left != null) {
					que.offer(root.left);
				}
				if (root.right != null) {
					que.offer(root.right);
				}
			}
		}
		return res;
	}
}
```