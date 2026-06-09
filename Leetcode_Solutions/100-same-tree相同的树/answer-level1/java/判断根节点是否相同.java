### 解题思路
判断左子树是否相同，判断右子树是否相同。

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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null) {
            return true;
        } else if(p !=null && q == null) {
            return false;
        } else if(p == null && q != null ) {
            return false;
        }
        boolean isRootSame = (p.val == q.val);
        return isRootSame && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
```