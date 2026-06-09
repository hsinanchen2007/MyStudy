### 解题思路
1. 递归返回布尔值。
2. 左右对称双参数递归。

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
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root,root);
    }
    private boolean isMirror(TreeNode t1,TreeNode t2) {
        if(Objects.isNull(t1) && Objects.isNull(t2)) {
            return true;
        }
        if(Objects.isNull(t1) || Objects.isNull(t2)) {
            return false;
        }
       return t1.val == t2.val && (isMirror(t1.left,t2.right) && isMirror(t1.right,t2.left));
    }
}
```