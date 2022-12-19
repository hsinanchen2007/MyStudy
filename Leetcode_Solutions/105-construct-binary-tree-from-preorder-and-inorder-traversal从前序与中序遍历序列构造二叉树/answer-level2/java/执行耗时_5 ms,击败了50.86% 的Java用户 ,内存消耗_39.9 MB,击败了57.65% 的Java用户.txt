```
class Solution {
    public TreeNode createTree(int[] preorder, int[] inorder, int leftone, int rightone, int lefttwo, int righttwo){
        if (leftone > rightone){
            return null;
        }
        int i;
        for (i = lefttwo;i<=righttwo;i++){
            if (inorder[i] == preorder[leftone])
                break;
        }
        TreeNode node = new TreeNode(inorder[i]);
        node.left = createTree(preorder,inorder,leftone+1, i-lefttwo+leftone,lefttwo,i-1);
        node.right = createTree(preorder,inorder,i-lefttwo+leftone+1,rightone,i+1,righttwo);
        return node;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder.length == 0 || inorder.length == 0){
            return null;
        }
        return createTree(preorder,inorder,0,preorder.length-1,0,inorder.length-1);

    }
}
```
