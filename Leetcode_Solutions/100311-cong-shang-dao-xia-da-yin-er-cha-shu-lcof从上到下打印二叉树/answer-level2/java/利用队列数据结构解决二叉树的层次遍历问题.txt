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
    public int[] levelOrder(TreeNode root) {
        if(root == null) return new int[0];
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		Queue<TreeNode> copy = new LinkedList<TreeNode>();
		queue.add(root);
		TreeNode current;
		while(!queue.isEmpty()) {
			current = queue.poll();
			copy.add(current);
			if(current.left != null) {
				queue.add(current.left);
			}
			if(current.right != null) {
				queue.add(current.right);
			}
		}
		int[] result = new int[copy.size()];
		for(int i = 0;i < result.length;i++) {
			result[i] = copy.poll().val;
		}
		return result;
    }
}
```