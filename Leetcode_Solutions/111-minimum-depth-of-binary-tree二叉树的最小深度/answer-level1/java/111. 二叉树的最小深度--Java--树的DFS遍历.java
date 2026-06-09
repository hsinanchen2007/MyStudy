### 解题思路
[Leetcode-Java(240+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_111_minDepth.java)

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
    /**
     * 解题思路：DFS求解
     * 1、求左子树的最小深度
     * 2、求右子树的最小深度
     * 3、求根节点的最小深度 = Math.min(left,right)+1
     * 
     * 需要注意一点：如左/右子树为空，得取有值得叶节点长度
     *
     * @param root
     * @return
     */
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        int left = minDepth(root.left);
        int right = minDepth(root.right);
        return (left == 0 || right == 0) ? left + right + 1 : Math.min(left, right) + 1;
    }
}
```