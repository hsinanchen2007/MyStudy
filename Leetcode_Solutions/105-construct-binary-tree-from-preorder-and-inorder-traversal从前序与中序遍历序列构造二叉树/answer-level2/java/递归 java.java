### 解题思路

通过记录数组下标的方式进行递归
### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(inorder.length==0||preorder.length==0) return null;
        TreeNode root=new TreeNode(preorder[0]);
        int i;
        for (i = 0; i < inorder.length; i++) {
            if (inorder[i]==preorder[0]) break;
        }
        root.left=build(1,i+1,preorder,0,i,inorder);
        root.right=build(i+1,preorder.length,preorder,i+1,inorder.length,inorder);
        return root;
    }
    private TreeNode build(int preBegin,int preEnd,int [] preOrder,int inBegin,int inEnd,int[] inOrder){
        if (preBegin==preOrder.length|| inBegin==preOrder.length|| preBegin>=preEnd || inBegin>=preEnd) return null;
        TreeNode root=new TreeNode(preOrder[preBegin]);
        int i=0;
        for (i = 0; i < preEnd - preBegin; i++) {
            if(inOrder[i+inBegin]==preOrder[preBegin])
            break;
        }
        root.left=build(preBegin+1,preBegin+1+i,preOrder,inBegin,inBegin+i,inOrder);
        root.right=build(preBegin+1+i,preEnd,preOrder,inBegin+i+1,inEnd,inOrder);
        return root;

    }
}
```