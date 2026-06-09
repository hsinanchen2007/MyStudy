    private class MyQueue {
		int level;
		TreeNode node;
		public MyQueue(int level, TreeNode node) {
			this.level = level;
			this.node = node;
		}
	}
	
	public List<List<Integer>> levelOrder(TreeNode root) {
		List<List<Integer>> list = new LinkedList<>();
		LinkedList<MyQueue> q = new LinkedList<>();
		if(root == null) return list;
		q.add(new MyQueue(0, root));
		while(!q.isEmpty()) {
			MyQueue mq = q.poll();
			int level = mq.level;
			TreeNode node = mq.node;
			if(level == list.size()) {	//说明list中还没有这一层
				List<Integer> list2 = new LinkedList<>();
				list.add(list2);
			}
			List<Integer> list3 = list.get(level);
			list3.add(node.val);
			if(node.left != null) {
				q.add(new MyQueue(level + 1, node.left));
			}
			if(node.right != null) {
				q.add(new MyQueue(level + 1, node.right));
			}
		}	
		return list;
	}