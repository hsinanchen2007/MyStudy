从 @追捕的风 处获得灵感，仿照中序遍历Moris算法，非递归添加指针。
  /**
	 * 如果节点有左子树，返回先序遍历中左子树的最后一个节点
	 * @return
	 */
	private TreeNode getLastLeftNode(TreeNode node){
		if(node.left == null)
			return node;
		
		TreeNode leftNode = node.left;
		//有右向右，无右向左，直到叶子节点
		while(leftNode.left != null || leftNode.right != null){
			if(leftNode.right != null){
				leftNode = leftNode.right;
			}
			else{
				leftNode = leftNode.left;
			}
		}
	    return leftNode;
	}
	
	public void flatten(TreeNode root) {
		if(root == null)
			return;
		
        TreeNode node = root, lastLeftNode;
        while(node != null){
        	//左右均有孩子，左边最后一个节点指向右孩子节点
        	if(node.left != null && node.right != null){
        		lastLeftNode = getLastLeftNode(node);
        		lastLeftNode.right = node.right;
        		node.right = node.left;
        		node.left = null;
        	}
        	//有左无右，直接切换
        	else if(node.left != null && node.right == null){
        		node.right = node.left;
        		node.left = null;
        	}
        	
        	node = node.right;
        }
	}