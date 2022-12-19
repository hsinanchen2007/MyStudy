简单的标记遍历和剪枝

```
class Solution {
    TreeNode ans = null;
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        findNode(root,p,q);
        return ans;
    }

    public boolean findNode(TreeNode root, TreeNode p, TreeNode q){
        if(root == null) return false;

        if(root.val == p.val && root.val == q.val){
            return true;
        }

        if(root.val == p.val && root.val != q.val){
            boolean left = findNode(root.left,q,q);
            boolean right = findNode(root.right,q,q);
            if(left || right){
                ans = root;
            }
            return true;
        }else if(root.val == q.val && root.val != p.val){
            boolean left = findNode(root.left,p,p);
            boolean right = findNode(root.right,p,p);
            if(left || right){
                ans = root;
            }
            return true;
        }

        boolean left = findNode(root.left,p,q);
        boolean right = findNode(root.right,p,q);

        if(ans!=null) return true;
        if(left && right) {
            ans = root;
            return true;
        }

        return left || right;
    }



}
```
