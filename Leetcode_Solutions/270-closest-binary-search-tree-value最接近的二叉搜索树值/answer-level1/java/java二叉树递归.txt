### 解题思路
使用min记录最小差值，result记录当前最接近的root值，接着递归：
如果 root为空，返回；
如果当前root最小差比min要小，则更新min与result；
如果目标值大于root，递归root.right否则递归root.left;
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
    private double min = Integer.MAX_VALUE;
    private int result;
    public int closestValue(TreeNode root, double target) {
        if (root == null) {
            return -1;
        }
        result = root.val;
        min = Math.abs(root.val - target);
        reverse(root, target);
        return result;
    }

    public void reverse(TreeNode root, double target) {
        if (root == null) {
            return;
        }

        int cur = root.val;
        if (Math.abs(cur - target) < min) {
            min = Math.abs(cur - target);
            result = cur;
        }
        if (target > cur) {
            reverse(root.right, target);
        } else if (target < cur) {
            reverse(root.left, target);
        } else {
            result = cur;
        }
        return ;
    }
}
```