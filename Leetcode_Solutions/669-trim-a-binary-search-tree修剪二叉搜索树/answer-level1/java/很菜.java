```
class Solution {
    private void fixBST(TreeNode root,int L,int R)
    {
        if(root==null)
        return;
        if(root.left!=null&&root.left.val<L)
        {
           root.left=root.left.right;
           fixBST(root,L,R);
        }
        if(root.right!=null&&root.right.val>R)
        {
            root.right=root.right.left;
            fixBST(root,L,R);
        } 
        fixBST(root.left,L,R);
        fixBST(root.right,L,R);
    }
    public TreeNode trimBST(TreeNode root, int L, int R) {
        if(root==null)
        return root;
        if(root.val<L)
        root=trimBST(root.right,L,R);
        else if(root.val>R)
        root=trimBST(root.left,L,R);
        fixBST(root,L,R);
        return root;
    }
}
```
