新方法Depth(TreeNode root, int dep)中，dep解决了递归时不能记录各各分支的深度这一缺点，无需分左右子树。
```
class Solution {
    
    public int maxDepth(TreeNode root) {
        int dep = 0;
        return Depth(root, dep);
    }
    public int Depth(TreeNode root, int dep){
        if(root == null) return dep;
        dep++;
        // System.out.println("val:" + root.val+" depth:"+res);
        return Math.max(Depth(root.left, dep), Depth(root.right, dep));
    }
}
```
