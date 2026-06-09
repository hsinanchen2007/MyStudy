### 解题思路
参考了大佬的思路

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

    Map<Integer, Integer> m = new HashMap<>();
    int[] preorder; 
    int[] inorder;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        this.preorder = preorder;
        this.inorder = inorder;
        for (int i = 0; i < inorder.length; i++) {
            m.put(inorder[i], i);
        }
        return build(0, 0, inorder.length - 1);
    }

    TreeNode build(int rootIndex, int inLeft, int inRight) {
        if (inLeft > inRight) return null;
        TreeNode root = new TreeNode(preorder[rootIndex]);
        int i = m.get(preorder[rootIndex]);
        root.left = build(rootIndex + 1, inLeft, i - 1);
        root.right = build(rootIndex + 1 + i - inLeft, i + 1, inRight);
        return root;
    }
}
```