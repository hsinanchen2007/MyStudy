    //1.递归
	public int maxDepth(TreeNode root) {
		if (root == null) return 0;
		return 1+Math.max(maxDepth(root.left), maxDepth(root.right));
    }
	//2.迭代
	public int maxDepth(TreeNode root) {
		int depth = 0;
		if (root == null) return depth;
		
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		TreeNode node = root;
		queue.offer(node);
		
		while (!queue.isEmpty()) {
			int count = queue.size();
			List<Integer> list = new ArrayList<>();
			while(count > 0 ) {
				node = queue.poll();
				list.add(node.val);
				if (node.left != null) queue.offer(node.left);
				if (node.right != null) queue.offer(node.right);
				count--;
			}
			depth++;
		}
		
		return depth;
    }