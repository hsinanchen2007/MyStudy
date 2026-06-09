### 解题思路
![屏幕快照 2020-03-06 20.12.48.png](https://pic.leetcode-cn.com/b921a496abcd08a3d13232cf8938dc5ba64fd59e6e616aac652a7711424c3fbc-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-06%2020.12.48.png)


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
    int pre = -1;
    boolean init = false;
    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }
        boolean left = isValidBST(root.left);
        if (init && root.val <= pre) {
            return false;
        } else {
            if (!init) {
                init = true;
            }
            pre = root.val;
        }
        return left && isValidBST(root.right);
    }
}
```