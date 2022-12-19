### 解题思路
此处撰写解题思路
把原来的答案修改了下，更容易看清楚

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
  public int minDepth(TreeNode root) {
    if (root == null) {
      return 0;
    }

    if ((root.left == null) && (root.right == null)) {
      return 1;
    }

    int min_leftDepth =  Integer.MAX_VALUE;
    int min_rightDepth =  Integer.MAX_VALUE;

    if (root.left != null) {
      min_leftDepth = minDepth(root.left);
    }
    if (root.right != null) {
      min_rightDepth = minDepth(root.right);
    }
    return Math.min(min_leftDepth, min_rightDepth) + 1;
  }
}

```