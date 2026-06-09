### 解题思路
**叶子节点满足条件，后续变量，一般节点，`首先要左子树相等，`然后才能使是root.val==root.left.val**

### 值判断之前，首先要全部子树满足条件(递归)
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
    private int ansCount = 0;

    private boolean isSame(TreeNode root) {
        if (root == null) {
            return true;
        }

        boolean isLeftOk = false;
        if (root.left == null || isSame(root.left) && root.val == root.left.val) {
            isLeftOk = true;
        }

        boolean isRightOk = false;
        if (root.right == null || isSame(root.right) && root.val == root.right.val) {
            isRightOk = true;
        }

        if (isLeftOk && isRightOk) {
            ansCount++;
            return true;
        }

        return false;
    }

    public int countUnivalSubtrees(TreeNode root) {
        isSame(root);
        return ansCount;
    }
}

```