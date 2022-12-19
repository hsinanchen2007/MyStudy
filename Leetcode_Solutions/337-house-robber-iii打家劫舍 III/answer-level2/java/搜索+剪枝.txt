### 解题思路
一开始的想法是暴力DFS，每一次递归返回当前节点最大的抢钱数，但是我把抢和不抢作为一个状态进行了分支，也就是说，同一个节点，抢和不抢是两颗树，会超时，参考了题解后发现每次递归可以直接返回一个数组int[2]，int[0]表示抢的最大结果，int[1]表示不抢的最大结果，这样就把一颗四叉树简化到了二叉树，大大提高了效率，这也体现了动态规划的思想，就是用数组把状态保存起来，而状态的转化就体现在递归不同层次的转移上

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

    public int rob(TreeNode root) {
        return Math.max(dfs(root)[0], dfs(root)[1]);
    }
    int[] dfs(TreeNode n) {
        if (n == null) return new int[2];
        int[] res = new int[2];
        int[] left = dfs(n.left);
        int[] right = dfs(n.right);
        res[0] = Math.max(left[0] + right[0], Math.max(left[0] + right[1], Math.max(left[1] + right[0], left[1] + right[1])));
        res[1] = left[0] + right[0] + n.val;
        return res;
    }
}
```