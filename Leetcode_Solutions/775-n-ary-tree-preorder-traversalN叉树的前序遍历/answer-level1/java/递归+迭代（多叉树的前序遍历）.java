	//1.递归
	public List<Integer> preorder(Node root) {
		List<Integer> list = new ArrayList<Integer>();
		if (root == null) return list;	
		list.add(root.val);
		
		pre_order(list, root.children);
		
		return list;	
    }
	
	public void pre_order(List<Integer> list, List<Node> subList) {
		if (subList == null || subList.size() == 0) return;
		
		for(Node n : subList) {
			if (n == null) return;
			list.add(n.val);
			pre_order(list, n.children);
		}
	}
	//2.迭代
	 public List<Integer> preorder(Node root) {
	        LinkedList<Node> stack = new LinkedList<>();
	        LinkedList<Integer> output = new LinkedList<>();
	        if (root == null) {
	            return output;
	        }

	        stack.add(root);
	        while (!stack.isEmpty()) {
	            Node node = stack.pollLast();
	            output.add(node.val);
	            if (node.children != null) {
	            	Collections.reverse(node.children);
		            for (Node item : node.children) {
		                stack.add(item);
		            }
	            }
	            
	        }
	        return output;
	    }