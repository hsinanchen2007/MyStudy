### 解题思路
首先在前序遍历中找到根节点root，前序遍历的根节点即是第一个点，再在中序遍历中找到这个根节点的位置，然后左边是这个节点的左子树，右边是这个节点的右子树，对左子树递归这个过程，将左子树返回的root节点作为根节点的左节点，右子树返回的root节点作为根节点的右节点即可；

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
        if(preorder == null || preorder.length<1){
            return null;
        }
        TreeNode[] tnArr = changeTreeNode(preorder);
        TreeNode root = tnArr[0];
        TreeNode leftNode = null;
        TreeNode rightNode = null;
        int i = 0;
        while(i<inorder.length-1){
            if(inorder[i] == tnArr[0].val){
                break;
            }else{
                i++;
            }
        }
        
            int[] l1 = new int[i];
            int[] l2 = new int[i];
            int[] r1 = new int[inorder.length-i-1];
            int[] r2 = new int[inorder.length-i-1];
            System.arraycopy(preorder,1,l1,0,i);//左子树的前序遍历数组
            System.arraycopy(inorder,0,l2,0,i);//左子树的中序遍历数组
            System.arraycopy(preorder,i+1,r1,0,preorder.length-i-1);//右子树的前序遍历数组
            System.arraycopy(inorder,i+1,r2,0,preorder.length-i-1);//右子树的中序遍历数组
            leftNode = buildTree(l1,l2);
            rightNode = buildTree(r1,r2);
            root.left = leftNode;
            root.right = rightNode;
            return root; 
    }
    //将数组转化为TreeNode数组
    public static TreeNode[] changeTreeNode(int[] preorder){
        TreeNode[] tnArr = new TreeNode[preorder.length];
        for(int i = 0; i<preorder.length;i++){
            tnArr[i] = new TreeNode(preorder[i]);
        }
        return tnArr;
    }
}
```