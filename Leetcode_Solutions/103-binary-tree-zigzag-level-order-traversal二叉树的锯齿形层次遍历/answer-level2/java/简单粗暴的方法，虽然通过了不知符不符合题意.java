### 解题思路
正向遍历树的每一层，在输出的时候通过bool值控制正向还是逆向!

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
   public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		List<List<Integer>> resp = new ArrayList<>();
		LinkedList<TreeNode> queue = new LinkedList<>();
		boolean flag = false;
		if (root != null) {
			queue.offer(root);
			while (!queue.isEmpty()) {
				List<Integer> item = new ArrayList<>();
				List<TreeNode> queueTmp = new ArrayList<>(queue);
				if (flag) {
					Collections.reverse(queueTmp);
				}
				for (TreeNode tree : queueTmp) {
					item.add(tree.val);
					queue.poll();
				}
				if (flag) {
					Collections.reverse(queueTmp);
				}
				for (TreeNode tree : queueTmp) {
					if (tree.left != null) {
						queue.offer(tree.left);
					}
					if (tree.right != null) {
						queue.offer(tree.right);
					}
				}
				resp.add(item);
				flag = !flag;
			}
		}
		return resp;
	}
}
```