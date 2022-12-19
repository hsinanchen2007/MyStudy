### 解题思路
一次成功，自我感觉很满足，哈哈哈哈
代码很简单，就是递归

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
        if(p != null && q == null)
            return false;
        else if(p == null && q != null)
            return false;
        else if(p == null && q == null)
            return true;
        if(p.val == q.val)
            return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
        else
            return false;    
    }
}
```