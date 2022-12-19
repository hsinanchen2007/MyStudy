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
    public TreeNode bstFromPreorder(int[] preorder) {
        if (null == preorder || preorder.length == 0) {
            return null;
        }
        return dfs(preorder,0,preorder.length - 1);
    }

    public TreeNode dfs(int[] preorder,int pL,int pR) {
        if (pL > pR) {
            return null;
        }
        int rootVal = preorder[pL];
        int i = 0;
        for (i = pL + 1; i <= pR; i++) {
            if (preorder[i] > rootVal) {
                break;
            }
        }
        TreeNode root = new TreeNode(rootVal);
        root.left = dfs(preorder,pL + 1,i - 1);
        root.right = dfs(preorder,i,pR);
        return root;
    }

    
}
```