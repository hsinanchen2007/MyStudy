### 解题思路
本题使用最优解**自底向上**判断一棵树是否为平衡二叉树

- 首先创建**递归方法体**，返回值为 `int` 类型

- 方法体里面先对传进来的结点**判空**，之后再分别递归的去遍历**左右子树的高度**，用 `-1` 来标记是否满足要求

- 最后判断左右子树的**高度差**是否小于 `2` 也就是不超过 `1`，如果满足就返回该高度并与 `-1` 比较即可。

### 代码

```java []
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
    public boolean isBalanced(TreeNode root) {
        return recur(root) != -1;        
    }
    
    private int recur(TreeNode node) {
        if (node == null) {
            return 0;
        }
        // 递归遍历左子树的高度
        int left = recur(node.left);
        if (left == -1) {
            return -1;
        }
        // 递归遍历右子树的高度
        int right = recur(node.right);
        if (right == -1) {
            return -1;
        }
        // 比较左右子树高度之差是否小于 2
        return Math.abs(left - right) < 2 ? Math.max(left, right) + 1 : -1;
    }
}
```