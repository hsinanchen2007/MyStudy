```

class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if(s==null || t==null){
            return false;
        }
        TreeNode r = same(s,t);        
        if(dfs(r,t)){
            return true;
        }
        if(isSubtree(s.left,t)){
            return true;
        }
        if(isSubtree(s.right,t)){
            return true;
        }
        return false; 
    }
    private TreeNode same(TreeNode s, TreeNode t){
        if(s==null || t==null){
            return null;
        }
        if(s.val == t.val){
            return s;
        }
        TreeNode r=same(s.left,t);
        if(r!=null){
            return r;
        }
        r=same(s.right,t);
        if(r!=null){
            return r;
        }
        return null;
    }

    private boolean dfs(TreeNode r, TreeNode t){
        if(r == null && t == null){
            return true;
        }
        if((r ==null && t!=null)||(r!=null && t==null)){
            return false;
        } 
        if(r.val != t.val){
            return false;
        }
        if(!dfs(r.left,t.left)){
            return false;
        }
        if(!dfs(r.right,t.right)){
            return false;
        }
        return true;
    }
}
```
