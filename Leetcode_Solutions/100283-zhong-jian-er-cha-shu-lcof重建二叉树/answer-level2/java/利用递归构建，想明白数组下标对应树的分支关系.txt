### 解题思路
递归，注意是利用数组构建构建二叉树，利用数组下标构建

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
     public TreeNode buildTree(int[] preorder,int[] inorder){
        return buildTreeCore(preorder,inorder,0,preorder.length-1,0,inorder.length-1);

    }

    public TreeNode buildTreeCore(int[] preorder,int[] inorder,int startPreorder, int endPreorder,int startInorder,int endInorder){
        if(startPreorder>endPreorder || startInorder>endInorder){
            return null;
        }
        //前序遍历的第一个是根节点
        int rootValue = preorder[startPreorder];
        TreeNode root = new TreeNode(rootValue);
        root.left=root.right=null;

        //从中序遍历结果中找出前序的根节点，分成左右子树
        int pos = 0;
        for (int i = 0; i < inorder.length; i++) {
            if (rootValue == inorder[i]){
               pos = i;
            }
        }
        //构建左子树
        int leftLen = pos-startInorder;
        root.left=buildTreeCore(preorder,inorder,
                   startPreorder+1,//左子树的前序开头,在前序序列数组中找位置
                    startPreorder+leftLen,//左子树前序结尾,在前序序列数组中找位置
                                startInorder,//左子树的中序开头,在中序序列数组中找位置
                     pos-1);//左子树中序结尾,在中序序列数组中找位置
        //构建右子树
        root.right=buildTreeCore(preorder,inorder,startPreorder+leftLen+1,
                endPreorder,pos+1,endInorder);
        return root;

    }
}
```