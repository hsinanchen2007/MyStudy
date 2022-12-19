### 解题思路
在遍历时每个节点时求两个值，一个是以当前节点开始的的最大值res，一个包含当前的最大值max。

![图片.png](https://pic.leetcode-cn.com/fee3f668a3df272ea2677dc51e43fe9121e8015514b25907a3068575329d7da8-%E5%9B%BE%E7%89%87.png)

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
    public int maxPathSum(TreeNode root) {
        maxPathSumTraverse(root);
        return maxPathSumResult;
    }

    private int maxPathSumResult = Integer.MIN_VALUE;

    private int maxPathSumTraverse(TreeNode node) {
        int max = node.val;
        int res = node.val;
        if (node.left != null) {
            int val = maxPathSumTraverse(node.left);
            max = Math.max(max, max + val);
            res = Math.max(res, node.val + val);
        }
        if (node.right != null) {
            int val = maxPathSumTraverse(node.right);
            max = Math.max(max, max + val);
            res = Math.max(res, node.val + val);
        }
        maxPathSumResult = Math.max(maxPathSumResult, max);
        //System.out.println(res + ":" + max);
        return res;
    }
}
```