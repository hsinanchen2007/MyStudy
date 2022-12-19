遍历二叉树 将每一层节点存在一个数组中，然后取所有数组末位数即可
    public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) { val = x; }
	}
	private class MyQueue {
		int level;
		TreeNode node;
		public MyQueue(int level, TreeNode node) {
			this.level = level;
			this.node = node;
		}
	}

	//实际上要返回每一层的最右边节点
	List<Integer> list = new LinkedList<>();
	List<List<Integer>> res = new LinkedList<>();
	public List<Integer> rightSideView(TreeNode root) {
		if(root == null) return list;
		rightSideView2(new MyQueue(0, root));
		for(int i = 0; i < res.size(); i ++) {
			int fina = res.get(i).size() - 1;
			list.add(res.get(i).get(fina));
		}
		return list;
    }
	private void rightSideView2(MyQueue mq) {
		int level = mq.level;
		TreeNode node = mq.node;
		if(level >= res.size()) {
			List<Integer> list2 = new LinkedList<>();
			res.add(list2);
		}
		res.get(level).add(node.val);
		if(node.left != null) rightSideView2(new MyQueue(level + 1, node.left));
		if(node.right != null) rightSideView2(new MyQueue(level + 1, node.right));
	}