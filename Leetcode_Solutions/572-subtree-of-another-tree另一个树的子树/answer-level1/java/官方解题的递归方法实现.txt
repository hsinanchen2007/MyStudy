
```
class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if(s == null && t == null){
            return true;
        }
        if(s == null || t == null){
            return false;
        }
        // 都不为null
        if(s != null && t != null){
            // 因为题中说s可以看着是s的子树，因此需要先判断s和t
            if(isSameTree(s, t)){
                return true;
            }
            // 递归判断左右
            if(isSubtree(s.left, t)){
                return true;
            }
            if(isSubtree(s.right, t)){
                return true;
            }
        }
        return false;
    }

    // 判断两颗树是否相等，所有节点相等
    private boolean isSameTree(TreeNode s, TreeNode t){
        // 都为null相等
        if(s == null && t == null){
            return true;
        }
        // 一个为null，不相等
        if(s == null || t == null){
            return false;
        }
        // 判断当前根节点是否相等，在递归判断左右节点
        return s.val == t.val && isSameTree(s.left, t.left) && isSameTree(s.right, t.right);
    }
}
```