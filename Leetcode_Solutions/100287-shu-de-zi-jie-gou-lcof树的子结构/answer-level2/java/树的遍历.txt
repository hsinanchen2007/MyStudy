### 解题思路
记住核心还是一颗二叉树的遍历

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
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        return (A != null && B != null) && (isTheSame(A, B) || isSubStructure(A.left, B) || isSubStructure(A.right, B));
    }

    boolean isTheSame(TreeNode A, TreeNode B) {
        if (B == null) return true;
        if (A == null || A.val != B.val) return false;
        return isTheSame(A.left, B.left) && isTheSame(A.right, B.right);
    }
}
```