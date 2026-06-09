### 解题思路
递归

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
    public TreeNode mirrorTree(TreeNode root) {
        if (root == null) return null;
        TreeNode mleft = mirrorTree(root.left);
        TreeNode mright = mirrorTree(root.right);
        root.left = mright;
        root.right = mleft;
        
        return root;
    }
}
```

执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
37.1 MB
, 在所有 Java 提交中击败了
100.00%
的用户