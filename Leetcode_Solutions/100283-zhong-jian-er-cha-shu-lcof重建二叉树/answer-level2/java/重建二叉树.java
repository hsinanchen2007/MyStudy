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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
             int length=preorder.length;
            if(preorder==null||length==0){return null;}//若数组为空，或数组长度为0
            if(inorder==null||length==0){return null;}
           
    TreeNode root = buildTree(preorder,0,length-1,inorder,0,length-1);//调用该函数得到根节点
        return root;//返回该树

    }


    public TreeNode buildTree(int[] preorder,int preorderStart,int preorderEnd,int[] inorder,int inorderStart,int inorderEnd){
        if(preorderStart>preorderEnd){return null;}//若数组只要两个元素

            int rootval=preorder[preorderStart];//根节点必须是前序遍历数组的第一个
             int rootIndex=0; //定义一个变量来表示根节点在中序遍历数组的第几个位置
         TreeNode root = new TreeNode(rootval);//构建一棵树，根节点为前序遍历第一个数
         
         if (preorderStart == preorderEnd) {//若数组只有一个元素，直接返回该节点
            return root;}

             for(int i=0;i<inorder.length;i++){
                 if(inorder[i]==rootval)
                   {rootIndex=i;}} //得到根节点在中序遍历数组的位置，也可以用Map存数组，可以快速得到位置。

        int leftNodes = rootIndex - inorderStart, rightNodes = inorderEnd - rootIndex;

    TreeNode  rootleft=buildTree( preorder,preorderStart+1,preorderStart+leftNodes, inorder,inorderStart,rootIndex-1);
    TreeNode  rootright=buildTree( preorder,preorderEnd - rightNodes + 1,preorderEnd, inorder,rootIndex+1,inorderEnd);

    root.left=rootleft;
    root.right=rootright;
    return root;
             }
       }


        

    

```