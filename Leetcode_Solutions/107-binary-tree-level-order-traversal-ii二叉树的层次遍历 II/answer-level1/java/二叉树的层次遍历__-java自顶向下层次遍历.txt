1、二叉树
2^k-1 二叉树是一个连通的无环图，并且每一个顶点的度不大于3。有根二叉树还要满足根结点的度不大于2。根节点有了之后，每个顶点定义了唯一的父节点，和最多2个子节点。然而，没有足够的信息来区分左右节点。如果不考虑连通性，允许图中有多个连通分量，这样的结构叫做森林。

2、二叉树的遍历
二叉树的遍历方式有前序、中序、后序和层次遍历。这里只需要用到层次遍历。

3、题解
使用自顶向下的深度遍历，逐层地去取同一层的所有节点。再结合LinkedList的addFirst将最新插入的数组放到头部，从而实现“自底向上”的效果。

代码：
```
public List<List<Integer>> levelOrderBottom(TreeNode root){
		// initialize the result
		LinkedList<List<Integer>> result= new LinkedList();
        // check the root not null
		if(root==null){return result;};
		
        // initialize the treenode of every level
		LinkedList<TreeNode> tree= new LinkedList();
        // root is the first level
		tree.add(root);
		
        // do the search till tree is null
		while(!tree.isEmpty()){
            //initialize the level to save result
			LinkedList<Integer> level=new LinkedList();
            // newTree to save the left and right node
			LinkedList<TreeNode> newTree= new LinkedList();
            
            //do the search till oldtree null
			while(!tree.isEmpty()){
				// save the reuslt of every node in the same level
				TreeNode node=tree.poll();
				level.add(node.val);
				
				// save the left and right node if present
				if(node.left!=null){
					newTree.add(node.left);
				}
				if(node.right!=null){
					newTree.add(node.right);
				}
				
			}
			// save the reuslt of every level
			result.addFirst(level);
			// set the tree of nexe level
			tree=newTree;
		}
		return result;
	}
```
