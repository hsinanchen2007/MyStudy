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
        int is = 0,
            ie = inorder.length - 1,
            ps = 0,
            pe = postorder.length - 1;
        
        if(ie < is ) return null;
        TreeNode result = new TreeNode(postorder[pe]);
        for(int i = is; i <= ie; i ++) {
            if(inorder[i] == result.val) {
                result.left = builderTree(inorder, postorder, is, i - 1, ps, ps + i - 1 -is);
                result.right = builderTree(inorder, postorder, i + 1, ie, ps + i -is, pe - 1);
                break;
            }
        }
        return result;
    }

    public TreeNode builderTree(int[] inorder, int[] postorder, int is, int ie, int ps, int pe) {
         if(ie < is ) return null;
        TreeNode result = new TreeNode(postorder[pe]);
        for(int i = is; i <= ie; i ++) {
            if(inorder[i] == result.val) {
                result.left = builderTree(inorder, postorder, is, i - 1, ps, ps + i - 1 -is);
                result.right = builderTree(inorder, postorder, i + 1, ie, ps + i -is, pe - 1);
                break;
            }
        }
        return result;
    }   
}
```