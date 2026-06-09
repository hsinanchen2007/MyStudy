### 解题思路
此处撰写解题思路

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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return creat(0, postorder.length-1, 0, inorder.length-1,inorder, postorder);

    }
    private TreeNode creat(int postL, int postR, int inL, int inR, int []inorder, int[] postorder){
        if(postL > postR){
            return null;//后序序列长度小于0，直接返回
        }
        TreeNode root = new TreeNode(postorder[postR]);//新建一个新的结点，用来存放当前二叉树的根节点,新节点的数据域为根节点的值

        int k = 0;
        for(k = inL; k < inR; k++){
            if(inorder[k] == postorder[postR]){
                break;
            }
        }

        int numleft = k - inL;//左子树节点的个数

        root.left = creat(postL, postL+numleft-1, inL, k-1, inorder, postorder);

        root.right = creat(postL+numleft, postR-1, k+1, inR, inorder, postorder);

        return root;
    }
}
```