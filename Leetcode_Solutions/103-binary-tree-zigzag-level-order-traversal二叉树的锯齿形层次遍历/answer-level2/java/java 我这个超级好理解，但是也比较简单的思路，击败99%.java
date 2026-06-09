![103题解.png](https://pic.leetcode-cn.com/0513028945676b61cbff597daa5407c6cd9dbea87a43bc988a3458aaec5f4c9a-103%E9%A2%98%E8%A7%A3.png)
首先 这个可以和“**102 二叉树的层次遍历**”结合起来

在102我的想法就很简单，在层次遍历时，用一个整数level记住当前在第几层，如果列表size小于当前层数，就先新建一个子列表，然后添加进去。

获取完层次遍历后的节点列表之后，再根据奇偶来翻转存取数字。
	    /*
	     * 先用愚蠢的方法，先按照之前的层次遍历，把每一次的节点存起来
	     * 然后再根据奇偶来决定遍历顺序，比较好空间和时间
	     */
 
```
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
	    	 List<List<Integer>>anslist =new ArrayList<List<Integer>>();
	    	 if (root==null )return anslist;
	    	 List<List<TreeNode>> ansNodes =new ArrayList<List<TreeNode>>();
	    	 findzigzagLevelOrder(root, 0, ansNodes);
	    	 for(int i=0;i<ansNodes.size();i++) {
	    		 List<Integer> alist=new ArrayList<Integer>();
	    		 anslist.add(alist);
	    		 if(i%2==0){// 如果是偶数 就是代表从左到右遍历节点
	    			 for(int j=0;j<ansNodes.get(i).size();j++) {
	    				 alist.add(ansNodes.get(i).get(j).val);
	    			 }
	    		 }else {// 奇数，从右到左
	    			 for(int j=ansNodes.get(i).size()-1;j>=0;j--) {
	    				 alist.add(ansNodes.get(i).get(j).val);
	    			 }
	    		 }
	    		 
	    	 }
	    	 return anslist;
	    }
```
// 以下是找层次遍历的方法，level用来标记当前处于第几层

 
```
    public void findzigzagLevelOrder(TreeNode root, int level,List<List<TreeNode>> ansNodes) {
	    	if( ansNodes.size()<level+1) {
	    		List<TreeNode>levelList =new ArrayList<TreeNode>();
	    		ansNodes.add(levelList);
	    	}
	    	ansNodes.get(level).add(root);
	    	if(root.left!=null) {
	    		findzigzagLevelOrder(root.left, level+1, ansNodes);
	    	}
	    	if(root.right!=null) {
	    		findzigzagLevelOrder(root.right, level+1, ansNodes);
	    	}
	    }
```

我这个比较暴力，还是要多多学习他人一次遍历的方法！