### 解题思路
两个递归：首先用isSubStructure来判断所有子结构。用dfs来判断是否两个节点是否所有结构相等。

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
        if (A == null || B == null) return false;
        return dfs(A,B) || isSubStructure(A.left, B) || isSubStructure (A.right, B);
    }

    public boolean dfs(TreeNode A, TreeNode B) {
        if (B == null) return true;
        if (A == null) return false;
        if (A.val != B.val) return false;

        return dfs(A.left, B.left) && dfs(A.right, B.right);
    }
}
```