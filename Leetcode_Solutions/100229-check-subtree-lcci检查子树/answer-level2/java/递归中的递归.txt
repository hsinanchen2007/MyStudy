执行用时 :1 ms, 在所有 Java 提交中击败了98.77%的用户
内存消耗 :42.5 MB, 在所有 Java 提交中击败了100.00%的用户

```
class Solution {
    public boolean checkSubTree(TreeNode t1, TreeNode t2) {
        if(t2 == null) return true;
        else if(t1 == null) return false;
        
        if(isEqual(t1 , t2)) return true;
        return checkSubTree(t1.left , t2) || checkSubTree(t1.right , t2);
    }

    public boolean isEqual(TreeNode r1 , TreeNode r2){
        if(r1 == null && r2 == null) return true;
        if(r1 == null || r2 == null) return false;
        if(r1.val == r2.val)
        {
            return isEqual(r1.left , r2.left) && isEqual(r1.right , r2.right);
        }
        return false; 
    }

}
```

