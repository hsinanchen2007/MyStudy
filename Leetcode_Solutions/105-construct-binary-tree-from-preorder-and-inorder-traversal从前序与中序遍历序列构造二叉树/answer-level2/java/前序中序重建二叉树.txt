### 解题思路
1. 根据前序的数，将中序切分，然后左右递归，详细看代码，注意需要四个指针。
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
        if(preorder == null || inorder == null || preorder.length == 0 || inorder.length == 0)
            return null;
        return dp(preorder, inorder, 0, inorder.length-1, 0, preorder.length-1);
    }

    public TreeNode dp(int[] preorder, int[] inorder, int istart, int iend, int pstart, int pend){
        if(istart > iend) return null;
        TreeNode root = new TreeNode(preorder[pstart]);
        for(int i = istart; i <= iend; i++){
            if(inorder[i] == preorder[pstart]){
                if(i > istart) root.left = dp(preorder, inorder, istart, i-1, pstart+1, pstart+i-istart);
                else root.left = null;
                if(i < iend) root.right = dp(preorder, inorder, i+1, iend, pend-iend+i+1, pend);
                else root.right = null;
            }
        }
        return root;
    }
}
```