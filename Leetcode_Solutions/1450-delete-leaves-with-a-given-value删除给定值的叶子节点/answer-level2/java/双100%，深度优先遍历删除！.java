### 解题思路
![屏幕快照 2020-02-29 14.19.57.png](https://pic.leetcode-cn.com/5208b30cbebf6a104d0cb3db2746f7a6820e1a597a98b96f9123cf0e98ef6c77-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-29%2014.19.57.png)


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
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        if (remove(root, target)) {
            return null;
        }
        return root;
    }

    private boolean remove(TreeNode node , int target) {
        if (node == null) {
            return false;
        }
        if (remove(node.left, target)) {
            node.left = null;
        }
        if (remove(node.right,target)) {
            node.right = null;
        }
        if (node.left == null && node.right == null && node.val == target) {
            return true;
        }
        return false;
    }
}
```