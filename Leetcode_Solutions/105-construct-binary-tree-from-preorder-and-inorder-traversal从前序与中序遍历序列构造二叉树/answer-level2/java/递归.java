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
        return buildTreeHelper(preorder, inorder, 0, preorder.length, 0, inorder.length);
    }

    public TreeNode buildTreeHelper(int[] preorder, int[] inorder, int pStart, int pEnd, int iStart, int iEnd){
        if(pStart==pEnd) return null;
        TreeNode root = new TreeNode(preorder[pStart]);
        int rootIndex=iStart;
        for(int i=iStart+1; i<iEnd; i++){
            if(inorder[i]==preorder[pStart]){
                rootIndex=i;
                break;
            }
        }

        root.left = buildTreeHelper(preorder, inorder, pStart+1, pStart+1+rootIndex-iStart, iStart, rootIndex);
        root.right = buildTreeHelper(preorder, inorder, pStart+1+rootIndex-iStart, pEnd, rootIndex+1, iEnd);
        return root;
    }
}
```