```
class Solution {
 public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null){
            return true;
        }else if (p == null || q == null){
            return false;
        }
        else if (p.val == q.val)
        {
            if ((p.left != null && q.left == null) || (p.left == null && q.left != null) || (p.right != null && q.right == null) || (p.right == null && q.right != null)){
                return false;
            }else {
                return isSameTree(p.left, q.left) && isSameTree(p.right,q.right);
            }
        }else {
            return false;
        }
    }
}
   
```