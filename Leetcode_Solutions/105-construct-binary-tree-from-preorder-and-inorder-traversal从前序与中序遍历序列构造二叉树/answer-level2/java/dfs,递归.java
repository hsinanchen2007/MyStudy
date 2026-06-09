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
        return dfs(preorder,inorder,0,preorder.length-1,0,inorder.length-1);
    }

    public TreeNode dfs(int[] preorder,int[] inorder, int pL, int pR,int iL, int iR) {
        if (pL > pR || iL > iR) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[pL]);
        int rootIndex = findRootInInOrder(inorder,preorder[pL]);
        int length = rootIndex - iL;
        root.left = dfs(preorder,inorder,pL + 1, pL + length,iL,rootIndex - 1);
        root.right = dfs(preorder,inorder,pL+ length + 1,pR,rootIndex + 1,iR);
        return root;
    }

    public int findRootInInOrder(int [] inorder ,int target) {
        for (int i = 0; i < inorder.length; i++) {
            if (inorder[i] == target) {
                return i;
            }
        }
        return -1;
    }
}
```