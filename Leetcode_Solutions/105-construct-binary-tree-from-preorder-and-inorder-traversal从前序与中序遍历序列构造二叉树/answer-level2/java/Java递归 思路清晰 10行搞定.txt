
```
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
            if(preorder.length == 0) return null;
            if(preorder.length == 1) return new TreeNode(preorder[0]);   //要先看题目返回的是什么 既然是节点 就可以本身函数进行左右返回
            int flag = preorder[0];
            int midi = inorder[0];
            TreeNode root = new TreeNode(flag);
            int temp = 0;
            for (int i = 0; i < inorder.length; i++) {
                if(flag == inorder[i]) temp = i;
            }
            root.left = buildTree(Arrays.copyOfRange(preorder,1,1+temp), Arrays.copyOfRange(inorder,0,temp));
            root.right = buildTree(Arrays.copyOfRange(preorder,temp+1,preorder.length), Arrays.copyOfRange(inorder,temp+1,inorder.length));
            return root;
    }
}
```
