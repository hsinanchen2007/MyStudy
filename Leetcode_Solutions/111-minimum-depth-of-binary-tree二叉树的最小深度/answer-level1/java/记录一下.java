### 解题思路
此处撰写解题思路

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
        int minLeft = Integer.MAX_VALUE,minRight = Integer.MAX_VALUE;
        if (root == null) return 0;
        if (root.left == null&& root.right == null){
            return 1;
        }
        if (root.left != null){
            minLeft = minDepth(root.left);
        }
        if (root.right != null){
            minRight = minDepth(root.right);
        }
        return Math.min(minLeft,minRight) + 1;

    }
}
```
# 遇到叶子结点返回1
# 递归给出左，右子树的最小深度
# 注意root=null的情况