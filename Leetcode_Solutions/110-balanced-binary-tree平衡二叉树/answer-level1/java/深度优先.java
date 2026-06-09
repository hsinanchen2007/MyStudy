```
class Solution {
    public boolean isBalanced(TreeNode root) {
        return !(DFS(root)==-1);           
    }
    public int DFS(TreeNode root){
        if(root==null)return 0;
        int left=DFS(root.left);
        int right=DFS(root.right);
        return (left==-1 || right==-1)?-1:(Math.abs(left-right)>1?-1:Math.max(left,right)+1);
    }
}
```
