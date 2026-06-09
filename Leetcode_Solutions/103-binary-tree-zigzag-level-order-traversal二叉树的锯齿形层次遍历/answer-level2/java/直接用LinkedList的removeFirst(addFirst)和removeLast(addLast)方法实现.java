```
	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		List<List<Integer>> list = new ArrayList<>();

		LinkedList<TreeNode> l1 = new LinkedList<>();
		LinkedList<TreeNode> l2 = new LinkedList<>();

		l2.add(root);
		int count = 0;
		while (!l1.isEmpty() || !l2.isEmpty()) {
			LinkedList<Integer> l = new LinkedList<>();
			if (count % 2 != 0) {
				while (!l1.isEmpty()) {
					TreeNode temp = l1.removeLast();
					if (temp.left != null)
						l2.addLast(temp.left);
					if (temp.right != null)
						l2.addLast(temp.right);
					l.addFirst(temp.val);
				}
			} else {
				while (!l2.isEmpty()) {
					TreeNode temp = l2.removeFirst();
					if (temp.left != null)
						l1.addFirst(temp.left);
					if (temp.right != null)
						l1.addFirst(temp.right);
					l.addLast(temp.val);
				}
			}
			count++;
			list.add(l);
		}
		return list;
	}
```
