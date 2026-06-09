我们很容易可以看到，每棵树或子树的左右子树交换之后就是正确答案了，那么我们可以用递归解决就OK
代码：
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if(root == null)
            return root;
        swapLeftRight(root);
        return root;
    }
    public void swapLeftRight(TreeNode node){
        if(node != null){
            if(node.left!=null || node.right!=null){
                TreeNode tmp = node.left;
                node.left = node.right;
                node.right = tmp;
                swapLeftRight(node.left);
                swapLeftRight(node.right);
            }
        }
    }
}