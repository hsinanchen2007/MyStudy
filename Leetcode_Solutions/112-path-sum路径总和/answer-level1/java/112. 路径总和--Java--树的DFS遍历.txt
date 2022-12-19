### 解题思路
[Leetcode-Java(240+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_112_hasPathSum.java)

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
     * 解题思路：
     * 1、sum减去当前根节点的val，将新的sum传递给左右子树
     * 2、左右子树重复步骤1
     * 3、如最终的节点==null并且sum==0则找到目标路径
     * 
     * 注意：叶节点的定义
     * @param root
     * @param sum
     * @return
     */
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false;
        return dfs(root, sum);
    }

    private boolean dfs(TreeNode root, int sum) {
        if (root == null) return sum == 0;
        int newSum = sum - root.val;
        if (root.left == null && root.right == null) return newSum == 0;
        boolean left = dfs(root.left, newSum);
        boolean right = dfs(root.right, newSum);
        if (root.left != null && root.right != null) return left || right;
        if (root.left != null) return left;
        if (root.right != null) return right;
        return false;
    }
}
```