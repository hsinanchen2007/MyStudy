```
public TreeNode addOneRow(TreeNode root, int v, int d) {
        //特殊情况
		if(root == null){
			return null;
		}if(d == 1){
			TreeNode newNode = new TreeNode(v);
			newNode.left = root;
			return newNode;
		}
		
		//按层遍历解
		int level = 1;
		Queue<TreeNode> queue = new LinkedList<>();
		queue.add(root);
		while(!queue.isEmpty()){
			int size = queue.size();
			if(level == d-1){//恰好到了第d-1层
				for(int i=0;i<size;i++){
					TreeNode p = queue.poll();
					if(p.left != null){
						TreeNode newNode = new TreeNode(v);
						newNode.left = p.left;
						p.left = newNode;
					}else{
						TreeNode newNode = new TreeNode(v);
						p.left = newNode;
					}
					if(p.right != null){
						TreeNode newNode = new TreeNode(v);
						newNode.right = p.right;
						p.right = newNode;
					}else{
						TreeNode newNode = new TreeNode(v);
						p.right = newNode;
					}
				}
			}else{
				for(int i=0;i<size;i++){
					TreeNode p = queue.poll();
					if(p.left!=null){
						queue.add(p.left);
					}if(p.right!=null){
						queue.add(p.right);
					}
				}
			}
			level ++;
		}
		return root;
    }
```
