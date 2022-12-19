
注意static提交时要去掉
```
public static TreeNode lastNode = null;

	/**
	 * \ 题目的难点在于n级别的遍历 常量级别空间。
	 * 
	 * 
	 * 思路如下，第一次中序，找出第一个顺序的节点
	 * 
	 * 第二次中序，将这个点的值和适当的值交换
	 * 
	 * @param root
	 */
	public static void recoverTree(TreeNode root) {
		if (root == null)
			return;

		/**
		 * 获取不按照顺序的node
		 */
		getNode(root);
		TreeNode targetNode = lastNode;
		System.out.println(targetNode.val);

		lastNode = null;
		getNode(root, targetNode);
		System.out.println(lastNode.val);
		
		
		int temp = targetNode.val;
		targetNode.val = lastNode.val;
		lastNode.val = temp;

	}

	public static boolean getNode(TreeNode node) {

		if (node.left != null)
			if (getNode(node.left))
				return true;

		if (lastNode == null)
			lastNode = node;

		if (node.val > lastNode.val)
			lastNode = node;

		if (node.val < lastNode.val)
			return true;

		if (node.right != null)
			if (getNode(node.right))
				return true;
		return false;
	}

	public static boolean getNode(TreeNode node, TreeNode targetNode) {
		if (node.left != null)
			if (getNode(node.left, targetNode))
				return true;

		if (lastNode == null)
			lastNode = node;
		if (node.val <= targetNode.val)
			lastNode = node;
		if (node.val > targetNode.val) {
			return true;
		}

		if (node.right != null)
			if (getNode(node.right, targetNode))
				return true;
		return false;
	}
```
