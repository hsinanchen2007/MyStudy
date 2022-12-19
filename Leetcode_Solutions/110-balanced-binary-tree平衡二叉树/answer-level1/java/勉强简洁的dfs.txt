```
class Solution {
    boolean flag=true;
    public boolean isBalanced(TreeNode root) {
        if(root==null) return true;
        dfs(root,1);
        return flag;
    }
    public int dfs(TreeNode root,int depth){
        if(root==null) return depth;
        int left=dfs(root.left,depth+1);
        int right=dfs(root.right,depth+1);
        if(Math.abs(left-right)>1)
            flag=false;
        return left>right?left:right;
    }
}
```
最近才学到dfs，对于那种只要有一个地方false，全局就false的问题，在方法外面设置一个flag会让代码简洁不少。