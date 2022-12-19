# 递归法
```
class Solution {
	public int maxDepth(TreeNode root) {
		if (root == null)
			return 0;
		return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
	}
}
```
# 层次遍历
```
class Solution {
	public int maxDepth(TreeNode root) {
		int res = 0;
		if (root == null)
			return res;
		Queue<TreeNode> queue = new LinkedList<>();
		// 根结点入队
		queue.add(root);
		while (!queue.isEmpty()) {
			int n = queue.size();
			for (int i = 0; i < n; i++) {
				TreeNode curNode = queue.poll();
				if (curNode.left != null)
					queue.add(curNode.left);
				if (curNode.right != null)
					queue.add(curNode.right);
			}
			res++;
		}
		return res;
	}
}
```