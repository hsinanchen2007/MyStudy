### 解题思路
以当前节点开始判断是否存在？
不存在进入left看是否存在？
不存在进入right看是否存在？

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
        if (B == null) {
            return false;
        }
        if (A == null) {
            return false;
        }
        
        return func(A, B) || isSubStructure(A.left, B) || isSubStructure(A.right, B);
    }

    private boolean func(TreeNode A, TreeNode B) {
        if (B == null) {
            return true;
        }
        if (A == null || A.val != B.val) {
            return false;
        }
        if (A.val == B.val) {
            return func(A.left, B.left) && func(A.right, B.right);
        }
        return false;
    }
}
```