两种方法都是基于中序遍历。
递归：
```
class Solution{
   public int minDiffInBST(TreeNode root) {
        findMinDiff(root);
        return minDifference;
    }
	private TreeNode pre=null;
	private int minDifference=Integer.MAX_VALUE;
	private void findMinDiff(TreeNode node) {
		if(node.left!=null)
			findMinDiff(node.left);
		if(pre!=null) {
			minDifference = Math.min(minDifference, node.val-pre.val);
		}
		pre=node;
		if(node.right!=null)
			findMinDiff(node.right);
	}
}
```
非递归：
class Solution{
	public int minDiffInBST1(TreeNode root) {
        int minDifference=Integer.MAX_VALUE;
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur=root, pre=null;
        while(!stack.isEmpty() || cur!=null) {
        	while(cur!=null) {
        		stack.push(cur);
        		cur=cur.left;
        	}
        	cur=stack.pop();
        	if(pre!=null) {
        		minDifference = Math.min(minDifference, cur.val-pre.val);
        	}
        	pre=cur;
        	cur=cur.right;
        }
        return minDifference;
    }
}