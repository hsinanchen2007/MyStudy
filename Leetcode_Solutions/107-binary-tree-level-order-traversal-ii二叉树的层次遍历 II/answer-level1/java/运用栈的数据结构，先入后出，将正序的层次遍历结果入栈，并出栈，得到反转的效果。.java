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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
		List<List<Integer>> lists = new ArrayList<List<Integer>>();
		level_Order_Bottom(root, lists);
		return lists;
    }
	
	public void level_Order_Bottom(TreeNode root,List<List<Integer>> lists) {
		if (root == null) return;
		Queue<TreeNode> queue = new LinkedList<>();
		queue.offer(root);
		
		Stack<List<Integer>> stack = new Stack<>();
		TreeNode node = root;
		while(!queue.isEmpty()) {
			int count = queue.size();
			List<Integer> list = new ArrayList<>();
			while(count > 0 ) {
				node = queue.poll();
				list.add(node.val);
				if (node.left != null) queue.offer(node.left);
				if (node.right != null) queue.offer(node.right);
				count--;
			}
			stack.push(list);
		}
		while(!stack.isEmpty()) {	
			lists.add(stack.pop());
		}
	}
}
```