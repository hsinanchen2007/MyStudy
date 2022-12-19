### 解题思路
就暴力递归判断完事了~~

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
        if (A == null || B == null) return false;  // 非空判断

        return match(A,B) || isSubStructure(A.left,B) || isSubStructure(A.right,B);  // 递归处理
    }

    private boolean match(TreeNode A, TreeNode B) {
        if (B == null) return true;           // 如果B树为空，则说明全匹配成功了
        if (A == null) return false;          // 如果A树为空（B树不为空），说明B没匹配完，即表示不匹配
 
        return  A.val == B.val && match(A.left,B.left) && match(A.right,B.right); // 前提条件OK，那么就继续判断~~
        
    }
}
```
执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :42.3 MB, 在所有 Java 提交中击败了100.00%的用户