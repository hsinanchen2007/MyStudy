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
        /*
            前序拿到根节点，在中序切分子树。
            子树分别拿根节点，再切分子树。
        */
    return buildSubTree(preorder,inorder,0,preorder.length-1,0,inorder.length-1);
    }
    TreeNode buildSubTree(int[] preorder,int[] inorder,
    int preorderStart,int preorderEnd,int inorderStart,int inorderEnd){
        if( inorderStart>inorderEnd ) return null;
        int rootVal = preorder[preorderStart];
        TreeNode root = new TreeNode(rootVal);
        // 找到rootVal在inorder的下标
        int inorderIndex = inorderStart;
        for( int i=inorderStart; i<=inorderEnd; i++ ){
            if( inorder[i] == rootVal ) inorderIndex=i;
        }
        // inorderIndex-inorderStart代表root左子树有几个节点
        int leftCount = inorderIndex-inorderStart;
        int rightCount = inorderEnd-inorderIndex;
        
        root.left = buildSubTree(preorder,inorder,preorderStart+1,preorderStart+leftCount,
            inorderStart,inorderIndex-1);
        
        root.right = buildSubTree(preorder,inorder,preorderStart+1+leftCount,preorderStart+1+leftCount+rightCount,
            inorderIndex+1,inorderEnd);
        // preorderStart+leftCount+rightCount
        return root;
    }
}
```