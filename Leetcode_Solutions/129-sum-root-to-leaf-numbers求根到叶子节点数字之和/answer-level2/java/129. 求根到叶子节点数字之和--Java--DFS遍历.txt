### 解题思路
[Leetcode-Java(240+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_129_sumNumbers.java)

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
    private int sum = 0;

    /**
     * 解题思路：
     * DFS遍历将之前的拼接节点代入，当到达叶节点后累加结果
     *
     * @param root
     * @return
     */
    public int sumNumbers(TreeNode root) {
        if (root == null) return 0;
        dfs("",root);
        return sum;
    }

    private void dfs(String preVal, TreeNode root) {
        if (root.left == null && root.right == null) {
            sum += Integer.parseInt(preVal + root.val);
            return;
        }
        if (root.left != null) {
            dfs(preVal + root.val, root.left);
        }
        if (root.right != null) {
            dfs(preVal + root.val, root.right);
        }
    }
}
```