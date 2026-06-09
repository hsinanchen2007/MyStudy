由题目描述可知，展开的链表顺序为二叉树的前序遍历顺序。
所以此题分为两步：
1.对二叉树进行前序遍历。
2.将遍历后的树进行重新封装成链表，令每个节点的left=null,right=当前节点的下一个节点。
此处只展示java代码。
```
    public void flatten(TreeNode root) {
		LinkedList<TreeNode> input = new LinkedList<>();
		//利用递归对二叉树的进行前序遍历。
		flat_ten(input, root);
		//将遍历后的树进行重新封装成链表，令每个节点的left=null,right=当前节点的下一个节点。
		while(!input.isEmpty()) {
			TreeNode node_cur = input.poll();
			TreeNode node_next = input.peek();
			node_cur.left = null;
			node_cur.right = node_next;
		}
    }
	
	//递归前序遍历
	public void flat_ten(LinkedList<TreeNode> input, TreeNode root) {
		if (root == null) return;
		
		input.offer(root);
		flat_ten(input,root.left);
		flat_ten(input,root.right);
	}
	
	//迭代前序遍历
	/*public void flat_ten(LinkedList<TreeNode> input, TreeNode root) {
		if (root == null) return;
		Stack<TreeNode> stack = new Stack<>();
		stack.push(root);
		
		while(!stack.isEmpty()) {
			TreeNode node = stack.pop();
			if (node == null) continue;
			input.offer(node);
			stack.push(node.right);			
			stack.push(node.left);
		}
	}*/
```

