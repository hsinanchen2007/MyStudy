```
class Solution {
    public TreeNode bstFromPreorder(int[] preorder) {
        return help(preorder,0,preorder.length-1);
    }
    public TreeNode help(int[] preorder,int left,int right){
        if(left>right)
            return null;
        TreeNode root=new TreeNode(preorder[left]);
        int tag=left+1;
        while(tag<preorder.length && preorder[tag]<preorder[left])
            tag++;
        root.left=help(preorder,left+1,tag-1);
        root.right=help(preorder,tag,right);
        return root;
    }
}
```
