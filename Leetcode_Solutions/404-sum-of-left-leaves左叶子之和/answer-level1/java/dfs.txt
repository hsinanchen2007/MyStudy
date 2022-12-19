### 解题思路
dfs
![image.png](https://pic.leetcode-cn.com/7e652750f34ddb33df6853bce1b88b2e2014ad5ee7b9003e1916bb845896c7a6-image.png)


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
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) {
            return 0;
        }
        doSumOfLeftLeaves(root.left, true);
        doSumOfLeftLeaves(root.right, false);
        return sumOfLeft;
    }

    int sumOfLeft = 0;
    private void doSumOfLeftLeaves(TreeNode root, boolean left) {
        if (root == null) {
            return ;
        }
        if (root.left == null && root.right == null) {
            if (left) {
                sumOfLeft += root.val;
            }
            return;
        }
        doSumOfLeftLeaves(root.left, true);
        doSumOfLeftLeaves(root.right, false);
    }
}
```