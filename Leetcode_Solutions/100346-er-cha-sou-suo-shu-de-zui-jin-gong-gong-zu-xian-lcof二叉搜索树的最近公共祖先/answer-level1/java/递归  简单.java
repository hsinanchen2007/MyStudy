```
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null)
            return null;
        int parentVal=root.val;
        int pVal=p.val;
        int qVal=q.val;

        if(pVal>parentVal&&qVal>parentVal)
            return lowestCommonAncestor(root.right,p,q);
        if(pVal<parentVal&&qVal<parentVal)
            return lowestCommonAncestor(root.left,p,q);

        return root;
    }
}
```
