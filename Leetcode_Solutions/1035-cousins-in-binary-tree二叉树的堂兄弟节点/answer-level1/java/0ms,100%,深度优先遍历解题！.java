### 解题思路
![屏幕快照 2020-03-02 11.09.44.png](https://pic.leetcode-cn.com/44c17b7ea87915e4820e0cf89180141be6b7f7fc0927a979f33dd11ec3e03b76-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-02%2011.09.44.png)


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
    public boolean isCousins(TreeNode root, int x, int y) {
        return depth(root, x, y, 0) == -1;
    }

    private int depth(TreeNode node, int x, int y , int level) {
        if (node == null) {
            return 0;
        }
        if (node.val == x || node.val == y) {
            return level;
        }
        int left = depth(node.left, x, y, level + 1);
        int right = depth(node.right,x, y, level + 1);
        if (left == right && left - level > 1) {
            return -1;
        }
        if (left != 0) {
            return left;
        }
        if (right != 0) {
            return right;
        }
        return 0;
    }
}
```