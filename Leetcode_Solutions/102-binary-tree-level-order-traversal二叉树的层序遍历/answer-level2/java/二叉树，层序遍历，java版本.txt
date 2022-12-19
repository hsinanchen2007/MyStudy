public List<List<Integer>> levelOrder(TreeNode root) {
		List<List<Integer>> lists = new ArrayList<List<Integer>>();
		level_Order(root, lists);
		return lists;
    }
	
	public void level_Order(TreeNode root,List<List<Integer>> lists) {
		if (root == null) return;
		Queue<TreeNode> queue = new LinkedList<>();
		queue.offer(root);
		
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
			lists.add(list);
		}
		
	}