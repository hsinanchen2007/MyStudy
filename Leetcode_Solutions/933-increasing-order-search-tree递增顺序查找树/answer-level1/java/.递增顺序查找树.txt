递归法，采用一个next指针记录下一个数的位置
```java
class Solution {
   public TreeNode increasingBST(TreeNode root) {
        return  increasingBST(root,null);
    }
    public TreeNode increasingBST(TreeNode root,TreeNode next){
        if(root==null) return null;
        if(root.right==null) root.right = next;
        else root.right = increasingBST(root.right,next);
        if(root.left==null) return root;
        next = root;
        TreeNode ans = increasingBST(root.left,next);
        root.left = null;

        return ans;
    }
}
```