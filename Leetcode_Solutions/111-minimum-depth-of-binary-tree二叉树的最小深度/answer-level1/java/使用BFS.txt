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
    public int minDepth(TreeNode root) {
    	int i = 0;
		if (root == null) {
			return i;
		}
		Deque<TreeNode> nodeQueues = new LinkedList<>();
		nodeQueues.add(root);
		nodeQueues.add(null);
		i++;
		while (!nodeQueues.isEmpty()) {
			TreeNode node = nodeQueues.poll();
			if (node != null) {
				if (node.left == null && node.right == null) {
					break;
				}
				if (node.right != null) {
					nodeQueues.add(node.right);
				}
				if (node.left != null) {
					nodeQueues.add(node.left);
				}
			} else {
				i++;
				if (nodeQueues.size() > 0) {
					nodeQueues.addLast(null);
				}
			}
		}
		return i;
    }
}
```