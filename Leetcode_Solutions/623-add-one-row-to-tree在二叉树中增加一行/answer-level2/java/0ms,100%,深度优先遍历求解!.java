### 解题思路
![屏幕快照 2020-03-02 12.30.46.png](https://pic.leetcode-cn.com/4cf9afbb8010435ee61f71f5a060e344740ea1b5b0e8ad87425adde92b79355f-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-02%2012.30.46.png)


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
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if (root == null) {
            return null;
        }
        if (d == 0) {
            return root;
        }
        if (d == 1) {
            TreeNode top = new TreeNode(v);
            top.left = root;
            return top;
        }
        if (d == 2) {
            if (root.left != null) {
                TreeNode l = new TreeNode(v);
                l.left = root.left;
                root.left = l;
            }
            if (root.right != null) {
                TreeNode r = new TreeNode(v);
                r.right = root.right;
                root.right = r;
            }
            if (root.left == null) {
                TreeNode l = new TreeNode(v);
                root.left = l;
                
            }
            if (root.right == null) {
                TreeNode r = new TreeNode(v);
                root.right = r;
            }
            return root;
        }
        root.left = addOneRow(root.left, v, d - 1);
        root.right = addOneRow(root.right, v, d - 1);
        return root;
    }
}
```