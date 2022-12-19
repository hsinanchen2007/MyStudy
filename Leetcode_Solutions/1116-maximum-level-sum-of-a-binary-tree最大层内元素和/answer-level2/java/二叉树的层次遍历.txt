```
public int maxLevelSum(TreeNode root) {
		if (root == null) {
			return 0;
		}
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		queue.offer(root);
		int MaxValue = root.val - 1;
		int Index = 0;
		int Level = 0;
		while (!queue.isEmpty()) {
			int size = queue.size();
			int sum = 0;
			Level++;// 记录层数
			while (size > 0) {
				size--;
				TreeNode curNode = queue.poll();
				sum += curNode.val;
				if (curNode.left != null) {
					queue.offer(curNode.left);
				}
				if (curNode.right != null) {
					queue.offer(curNode.right);
				}
			}
			if (sum > MaxValue) {
				MaxValue = sum;
				Index = Level;
			}
		}
		return Index;
	}
```
