### 解题思路
建议大家先看 第543.二叉树直径 这道题，其实这个思想和那个题是一样的
对于每一个节点，我们求出他的最大左子树深度和最大右子树深度并且求两个深度的差的绝对值
遍历所有的节点，找到所求的差的最大值。如果这个最大值大于1，那么这棵树就不是一个平衡二叉树。
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
    private int ans = 1;

    public boolean isBalanced(TreeNode root) {
        int min = Integer.MAX_VALUE;
        getDeepth(root);
        if(ans <= 1)
            return true;
        else
            return false;
    }
    public int getDeepth(TreeNode root)
    {
        if(root == null)
            return ans;
        int L = getDeepth(root.left);
        int R = getDeepth(root.right);
        ans = Math.max(ans,Math.abs(L-R));

        return Math.max(L,R)+1;
    }
}
```