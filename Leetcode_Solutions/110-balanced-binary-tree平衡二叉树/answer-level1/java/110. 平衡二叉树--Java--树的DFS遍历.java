### 解题思路
[Leetcode-Java(240+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_110_isBalanced.java)

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
import javafx.util.Pair;


class Solution {
    /**
     * 解题思路：
     * 1、递归计算左右子树的高度
     * 2、取左右子树的最大高度+1，即是该根节点的高度
     * 3、由于每个节点都需要满足高度平衡二叉树的条件，所以递归返回一个Pair<Boolean,Integer>
     * @param root
     * @return
     */
    public boolean isBalanced(TreeNode root) {
        return dfs(root).getKey();
    }

    private Pair<Boolean, Integer> dfs(TreeNode root) {
        if (root == null) return new Pair<>(true, 0);
        Pair<Boolean, Integer> left = dfs(root.left);
        Pair<Boolean, Integer> right = dfs(root.right);
        return new Pair<>(left.getKey() && right.getKey() && (Math.abs(left.getValue() - right.getValue()) <= 1), Math.max(left.getValue(), right.getValue()) + 1);
    }
}
```