### 解题思路
分两种情况讨论，对于给定的根节点i：
（1）若结果集中不包含节点i，则最大值为节点i的左右子树的最大值之和
（2）若结果集中包含节点i，则最大值为节点i的权重加左右子树的最大值之和且不包含左右子节点自身权重
由此可见问题符合最优性原理（问题一个实例的最优解总是包含其所有子实例的任意最优解），可以使用动态规划自底向上构建最优解。

设f(i)为以节点i为根的子树的最大权重值，A[i]为节点i的权重，G[i][0]为节点i在不包含自身时的最大权重，G[i][1]为节点i在包含自身时的最大权重，则：
```
f(i) = max(G[i][0], G[i][1])
G[i][0] = max(G[i.left][0], G[i.left][1]) + max(G[i.right][0], G[i.right][1])
G[i][1] = A[i] + G[i.left][0] + G[i.right][0]
```
求解f(root)即为最优值。

例如，对于如下的满二叉树，自底向上求解则有：
```
      1
    /   \
   2     3
  / \   / \ 
 4   5 6   7
```
```
G[7][0] = 0
G[7][1] = 7
G[6][0] = 0
G[6][1] = 6
G[5][0] = 0
G[5][1] = 5
G[4][0] = 0
G[4][1] = 4
G[3][0] = max(G[6][0], G[6][1]) + max(G[7][0], G[7][1]) = 6 + 7 = 13
G[3][1] = 3 + G[6][0] + G[7][0] = 3
G[2][0] = max(G[4][0], G[4][1]) + max(G[5][0], G[5][1]) = 4 + 5 = 9
G[2][1] = 2 + G[4][0] + G[5][0] = 2
G[1][0] = max(G[2][0], G[2][1]) + max(G[3][0], G[3][1]) = 9 + 13 = 22
G[1][1] = 1 + G[2][0] + G[3][0] = 1 + 9 + 13 = 23
f(root) = f(1) = max(G[1][0], G[1][1]) = max(22, 23) = 23
```

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
        int[] res = work(root);
        return Math.max(res[0], res[1]);
    }

    int[] work(TreeNode t) {
        int[] res = new int[2];
        if (t == null) return res;
        int[] leftRes = work(t.left);
        int[] rightRes = work(t.right);                
        res[0] = Math.max(leftRes[0], leftRes[1]) + Math.max(rightRes[0], rightRes[1]);
        res[1] = t.val + leftRes[0] + rightRes[0];
        return res;
    }
}
```