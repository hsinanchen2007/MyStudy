思路：
该方法有一个前提：树不为空，为空需要多设计一个方法
1、首先找出根节点左子树的最右子节点，判断根节点值是否大于该值
2、然后找出根节点右子树的最左子节点，判断根节点值是否小于该值
3、满足上述条件的情况下，采用递归的方法判断左子树和右子树是否满足二叉搜索树的要求
```
class Solution {
    public boolean isValidBST(TreeNode root) {
        if(root == null) return true;
        TreeNode lefttemp = new TreeNode(0), righttemp = new TreeNode(0);
        boolean ans = true;
        if(root.left != null){
            lefttemp = root.left;
            while(lefttemp.right != null){
                lefttemp = lefttemp.right;
            }
            if(root.val<=lefttemp.val){
                ans = false;
            }
        }
        if(root.right != null){
            righttemp = root.right;
            while(righttemp.left != null){
                righttemp = righttemp.left;
            }
            if(root.val>=righttemp.val){
                ans = false;
            }
        }
        return isValidBST(root.left) && isValidBST(root.right) && ans;
    }
}
```