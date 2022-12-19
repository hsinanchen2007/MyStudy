### 解题思路
递归很优雅，但是总是用不太好，可能熟能生巧，这个题目的递归写的还可以，清晰。

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

    public int sumOfLeftLeaves(TreeNode root) {
        calSum(root, false);
        return sum;
    }

    private void calSum(TreeNode root, boolean isLeft) {
        if (root == null) {
            return;
        }
        if (isLeft && root.left == null && root.right == null) {
            sum += root.val;
            return;
        }
        calSum(root.left,true);
        calSum(root.right,false);
    }
}
```