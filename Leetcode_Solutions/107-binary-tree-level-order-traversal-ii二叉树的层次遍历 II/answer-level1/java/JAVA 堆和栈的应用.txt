  public List<List<Integer>> levelOrderBottom(TreeNode root) {

    	List<List<Integer>> res = new ArrayList<List<Integer>>();
    	if (root == null ) {
    		return res;
    	}
    	
    	Stack<List<Integer>> stack = new Stack<List<Integer>>();
    	Queue<TreeNode> queue = new LinkedList<TreeNode> ();
    	queue.add(root);
    	
    	while(!queue.isEmpty()){
    		int curNum = queue.size();
    		List<Integer> list = new ArrayList<Integer>();
    		for(int i = 0 ; i <curNum ; i++){
    			TreeNode node = queue.poll();
    			list.add(node.val);
    			
        		if(node.left!=null){
        			queue.offer(node.left);
        		}
        		if(node.right!=null){
        			queue.offer(node.right);
        		}
    		}
    		
    		stack.add(list);
    		
    	}

      while(!stack.isEmpty()){
    	  
    	  res.add(stack.pop());
      }

        return res;
    }