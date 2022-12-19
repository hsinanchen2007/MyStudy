### 解题思路
1. 递归记录每层的层级
2. 当遇到叶子节点时，与最小值最小层级进行比较

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
        if(root == null) return 0;
        helper(root, 1);
        return min;
    }

    int min = Integer.MAX_VALUE;
    void helper(TreeNode node,int level){
        if(node.left == null && node.right == null){
            min = Math.min(min, level);
            return;
        }
        if(node.left != null){
            helper(node.left, level + 1);
        }
        if(node.right != null){
            helper(node.right, level + 1);
        }

    }
}
```