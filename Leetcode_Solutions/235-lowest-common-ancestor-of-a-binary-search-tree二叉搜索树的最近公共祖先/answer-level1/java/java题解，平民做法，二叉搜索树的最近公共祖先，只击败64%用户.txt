因为本题是二叉搜索树，所以要利用好BST里的“左子树的值全都小于当前root的值，右子树的值都大于当前root的值”这一点。

class Solution {
    TreeNode res;
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if((p.val<=root.val&&q.val>=root.val)||(p.val>=root.val&&q.val<=root.val))
            res = root;  //因为可能p比q大，也可能p比q小
        else if(p.val<=root.val&&q.val<=root.val)
            lowestCommonAncestor(root.left,p,q);//如果p和q都小于等于当前root的值，则说明p和q在当前根的左子树里
        else if(p.val>=root.val&&q.val>=root.val)
            lowestCommonAncestor(root.right,p,q);//如果p和q都大于等于当前root的值，则说明p和q在当前根的右子树里
        return res;
    }
   
}
![1.png](https://pic.leetcode-cn.com/435f3972f8bbdd2f9c6e10bccf9a89a3202dad1d74f53e7101f430dc29e1d65a-1.png)
