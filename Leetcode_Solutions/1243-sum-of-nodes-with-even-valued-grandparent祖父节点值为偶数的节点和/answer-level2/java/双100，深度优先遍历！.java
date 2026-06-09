### 解题思路
![屏幕快照 2020-02-25 14.04.35.png](https://pic.leetcode-cn.com/ffc0c8825adfb9958b2caf0dd616c139680aa2333da23cc82fad0b4f2274ca3d-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-25%2014.04.35.png)


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
    int sum = 0;
    public int sumEvenGrandparent(TreeNode root) {
        if (root == null) {
            return sum;
        }
        dfs(root, 1);
        return sum;
    }

    private void dfs(TreeNode node, int parent) {
        if (node == null) {
            return;
        }
        if (parent % 2 == 0) {
            if (node.left != null) {
                sum += node.left.val;
            }
            if (node.right != null) {
                sum += node.right.val;
            }
        }
        dfs(node.left, node.val);
        dfs(node.right, node.val);
    }
}
```