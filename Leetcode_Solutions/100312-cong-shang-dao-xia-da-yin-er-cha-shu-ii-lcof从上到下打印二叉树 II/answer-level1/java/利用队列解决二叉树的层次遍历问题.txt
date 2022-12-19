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
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root == null) return new LinkedList<List<Integer>>();
		List<List<Integer>> lists = new LinkedList<List<Integer>>();
		List<Integer> list = new LinkedList<Integer>();
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		queue.add(root);
		TreeNode current = root;
		while(!queue.isEmpty()) {
			int size = queue.size();
			for(int i = 0;i<size;i++) {
				current = queue.poll();
				list.add(current.val);
				if(current.left != null) {
					queue.add(current.left);
				}
				if(current.right != null) {
					queue.add(current.right);
				}
			}
			lists.add(new LinkedList<>(list));
			list.clear();
		}
		return lists;
    }
}
```