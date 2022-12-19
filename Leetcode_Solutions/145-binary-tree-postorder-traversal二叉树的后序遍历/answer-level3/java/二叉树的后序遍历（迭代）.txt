利用栈先进后出，跟前序和中序遍历时区别在于，根节点不能直接出栈。首先将root节点入栈，循环以下操作直到栈为空。
 判断栈顶元素是否符合以下两个条件之一：
   1：符合当前栈顶节点是叶子节点
   2：我们用一个变量保存上一次出栈时的节点，符合该节点是当前栈顶节点的子节点。
 当满足条件，栈顶元素出栈并访问，不符合则将栈顶的right，left依次入栈。
  class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
		   Stack<TreeNode> stack = new Stack<>();
		    LinkedList<Integer> output = new LinkedList<>();
		    if (root == null) {
		      return output;
		    }
		    TreeNode lastNode=root;//记录上一次访问的节点
		    stack.push(root);
		    while (!stack.isEmpty()) {
		      TreeNode node=stack.peek();
		      if((node.left==null && node.right==null) ||(node.right==lastNode || node.left==lastNode)) {
		    	  lastNode=stack.pop();
		    	  output.add(lastNode.val);
		      }else {
		    	  if(node.right!=null)
		    	    stack.push(node.right);
		    	  if(node.left!=null)
		    	  stack.push(node.left);
		      }
		  }
		    return  output;
	    }
	 
}