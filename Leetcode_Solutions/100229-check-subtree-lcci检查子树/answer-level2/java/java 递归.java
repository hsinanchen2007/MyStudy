issub函数递归判断以该节点为头节点的树是否与t2相同
checksubtree函数中判断根节点是否与t2相同，再分别判断左子树，右子树，取或，有一个成立即可


```
class Solution {
    public boolean checkSubTree(TreeNode t1, TreeNode t2) {
        if(t1 == null && t2 == null) return true;
        if(t1 == null || t2 == null ) return false;
        return issub(t1 , t2) || checkSubTree(t1.left , t2) || checkSubTree(t1.right , t2);

    }
    public boolean issub(TreeNode t1 , TreeNode t2){
        if(t1 == null && t2 == null) return true;
        if(t1 == null || t2 == null || t1.val != t2.val) return false;
        return issub(t1.left , t2.left) && issub(t1.right , t2. right);
    }
}
```
