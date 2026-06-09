### 解题思路
递归实现，思路见注解

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
        if (A == null || B == null) {
            return false;
        }
        return isSubStructureRecursion(A, B, false);
    }

    private boolean isSubStructureRecursion(TreeNode A, TreeNode B, boolean sta) {
        // 如果 A 为空而 B 不为空，则一定是 false
        // 除此之外，还有两种情况:
        // 1、A 为空且 B 为空，即 B 正好是 A 的完整子树
        // 2、B 直接为空，即 B 是 A 的不完整子树（一部分)
        if (A == null) {
            if (B == null) {
                return true;
            }
            return false;
        } 
        if (B == null) {
            return true;
        }

        // 因为是两棵树，节点引用不相同
        if (A.val == B.val) {
            boolean sta1 = isSubStructureRecursion(A.left, B.left, true);
            boolean sta2 = isSubStructureRecursion(A.right, B.right, true);
            
            return sta1 && sta2;
        }
        // 如果已经是中间节点，则不往下继续判断
        if (sta == true) {
            return false;
        }
        if (isSubStructureRecursion(A.left, B, false) || isSubStructureRecursion(A.right, B, false)) {
            return true;
        }
        return false;
    }
}
```