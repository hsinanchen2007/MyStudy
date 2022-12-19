### 解题思路
采用迭代的方法，对于一个二叉搜索树的节点来说，它的左节点必定小于其，右节点必定大于其，所以只要使用迭代的方法遍历所有节点的左子树和右子树便可。直到左、右子树没有节点为止。

时间复杂度：O(n)
空间复杂度: O(n)

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
    public boolean isValidBST(TreeNode root) {
        return helper(root, null, null);
    }

    public boolean helper(TreeNode root, Integer min, Integer max){
        if (root == null){
            return true;
        }

        int val = root.val;
        if (min != null && val <= min){
            return false;
        }
        if (max != null && val >= max){
            return false;
        }

        return helper(root.left, min, val) && helper(root.right, val, max);
    }
}
```