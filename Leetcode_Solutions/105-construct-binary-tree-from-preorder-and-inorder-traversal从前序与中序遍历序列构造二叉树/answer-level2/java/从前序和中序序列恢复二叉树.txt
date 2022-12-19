```java []
class Solution {
    public TreeNode dfs(int[] preorder, int[] inorder, int start_p, int end_p, int start_i, int end_i){
        if(start_p>end_p) return null;
        if(start_p==end_p) return new TreeNode(preorder[start_p]);
        int head=preorder[start_p];
        int i=start_i;
        for(;i<=end_i;i++)
            if(inorder[i]==head) break; //找根
        TreeNode root=new TreeNode(head);
        root.left=dfs(preorder,inorder,start_p+1,start_p+i-start_i,start_i,i-1);  //切割
        root.right=dfs(preorder,inorder,end_p+i+1-end_i,end_p,i+1,end_i);
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder.length==0) return null;
        return dfs(preorder,inorder,0,preorder.length-1,0,preorder.length-1);
    }
}
```
