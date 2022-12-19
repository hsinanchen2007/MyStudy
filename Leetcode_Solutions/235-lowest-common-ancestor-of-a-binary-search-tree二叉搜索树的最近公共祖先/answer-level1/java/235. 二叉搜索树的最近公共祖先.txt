/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/8/30
 *
 * 解题思路： 不多说,两种,可简单可复杂 , 用上二叉搜索树的性质
 */
```
    public TreeNode lowestCommonAncestor2(TreeNode root, TreeNode p, TreeNode q) {
        if((root.val >= p.val && root.val <= q.val) || ((root.val <= p.val && root.val >= q.val)) || (root.val == p.val) || (root.val == q.val)){
            return root;
        }

        TreeNode res = null;
        if(p.val > q.val){
            if(root.val > p.val){
                res = lowestCommonAncestor(root.left , p , q);
            }else if(root.val < q.val){
                res = lowestCommonAncestor(root.right , p , q);
            }
        }else if(p.val < q.val){
            if(root.val > q.val){
                res = lowestCommonAncestor(root.left , p , q);
            }else if(root.val < p.val){
                res = lowestCommonAncestor(root.right , p , q);
            }
        }else{
            if(root.val > p.val){
                res = lowestCommonAncestor(root.left , p , q);
            }else if(root.val < p.val){
                res = lowestCommonAncestor(root.right , p , q);
            }
        }
        return res;
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        if((p.val > root.val && q.val > root.val)){
            return lowestCommonAncestor(root.right,p,q);
        }else if((p.val < root.val && q.val < root.val)) {
            return lowestCommonAncestor(root.left, p, q);
        }else{
            return root;
        }
    }
```