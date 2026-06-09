```

    public boolean isSubStructure(TreeNode A, TreeNode B) {

        if (B == null || A == null)
            return false;
        if (A != null && B != null && A.val == B.val){
            return isTree(A,B);
        }
        
        if (isSubStructure(A.left,B))
            return true;
        if (isSubStructure(A.right,B))
            return true;
        return false;
    }
    private boolean isTree(TreeNode a,TreeNode b){
        if ( b == null )
            return true;
        
        if (a!= null && b!=null && a.val != b.val)
            return false;
        
        if (a!= null && b!=null && a.val == b.val)
            return isTree(a.left,b.left) && isTree(a.right,b.right);
        return false;
    }
```
