### 解题思路
递归创建二叉树节点不难
此题的重点 如何构建出二叉树的节点 并链接上去
切记切记

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
      
        //构建二叉树 + 并链接

        //递归构建二叉树
        return buildBinaryTree(preorder, 0, preorder.length, inorder, 0, inorder.length); 
    }


    //递归构建二叉树
    public TreeNode buildBinaryTree(int [] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd) {
        
        //递归终止条件
        if (preStart >= preEnd || inStart >= inEnd) {
            return null;
        }
        
        //构建二叉树节点
        TreeNode pre = new TreeNode(preorder[preStart]);

        //System.out.println(pre.val);

        //找出中序遍历的中间节点
        int mid = 0;
        for (int i = inStart; i < inEnd; i++) {
            if (preorder[preStart] == inorder[i]) {//找到了
                mid = i;
                break;
            }
        }

        //连接左区间 左子树
        pre.left = buildBinaryTree(preorder, preStart + 1, preStart + mid + 1 - inStart, inorder, inStart, mid);

        //连接右区间 右子树
        pre.right = buildBinaryTree(preorder, preStart + mid + 1 - inStart, preEnd, inorder, mid + 1, inEnd);
       
        
        return pre;
    }
}
```