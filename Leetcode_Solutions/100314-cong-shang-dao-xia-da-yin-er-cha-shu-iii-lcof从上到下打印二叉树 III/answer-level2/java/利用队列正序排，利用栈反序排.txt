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
		Stack<TreeNode> stack = new Stack<TreeNode>();
		int ceng = 0;
		queue.add(root);
		TreeNode current = root;
		while(!queue.isEmpty()) {
			ceng++;
			int size = queue.size();
			for(int i = 0;i<size;i++) {
				current = queue.poll();
				if(ceng%2 == 1)
					list.add(current.val);
				else
					stack.push(current);
				if(current.left != null) {
					queue.add(current.left);
				}
				if(current.right != null) {
					queue.add(current.right);
				}
			}
			if(ceng%2 == 1)
				lists.add(new LinkedList<>(list));
			else {
				int stackSize = stack.size();
				for(int i = 0;i < stackSize;i++) {
					list.add(stack.pop().val);
				}
				lists.add(new LinkedList<>(list));
			}
//			stack.clear();
			list.clear();
		}
		return lists;
    }
}
```