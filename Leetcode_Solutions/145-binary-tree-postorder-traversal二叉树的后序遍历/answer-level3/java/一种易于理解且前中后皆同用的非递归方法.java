通过自定义一个工具类  帮助我们实现前中后序遍历

    class MyCommand {
		String s;	//这里的 s 只有两个值  go代表访问到该节点，print代表打印(记录)该节点
		TreeNode node;
		public MyCommand(String s, TreeNode node) {
			this.s = s;
			this.node = node;
		}
	}	
	public List<Integer> postorderTraversal(TreeNode root) {
		LinkedList<Integer> list = new LinkedList<>();
		Stack<MyCommand> stack = new Stack<>();
		if(root == null) return list;
		stack.push(new MyCommand("go", root));
		while(!stack.isEmpty()) {
			MyCommand mc = stack.pop();
			if(mc.s.equals("print")) {	//如果需要记录   就记录之
				list.add(mc.node.val);
			}else {
				assert mc.s.equals("go");
				stack.push(new MyCommand("print", mc.node));
				if(mc.node.right != null) {
					stack.push(new MyCommand("go", mc.node.right));
				}
				if(mc.node.left != null) {
					stack.push(new MyCommand("go", mc.node.left));
				}
			}
		}
		return list;
	}
