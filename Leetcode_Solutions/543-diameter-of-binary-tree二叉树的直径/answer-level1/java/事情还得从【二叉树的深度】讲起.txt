### 解题思路
先看另外一道题：
**【Leetcode104】给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。**

这道题的思路是每个节点的深度是左右两子树深度更大的那个再+1（加自己这一层的深度）
代码可以写做下面这样

```java
class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int left = maxDepth(root.left);
        int right = maxDepth(root.right);
        return Math.max(left, right) + 1;
    }
}
```

再回到这道题上来，二叉树的直径一定是某一点的**左右两子树深度之和**，所以我们遍历所有节点，并维护一个最大值，就可以找到答案
至于如何求右两子树的深度，就可以借用上面的（狗头）
换言之，我们可以通过在求二叉树最大深度的同时，维护一个左右两子树深度之和的最大值，这个值就是该二叉树的直径了

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
    int longest;
    
    public int diameterOfBinaryTree(TreeNode root) {
        longest = 0;
        maxDepth(root);
        return longest;
    }

    public int maxDepth(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int left = maxDepth(root.left);
        int right = maxDepth(root.right);
        longest = Math.max(longest, left + right);//除了这一行其他都一样
        return Math.max(left, right) + 1;
    }
}
```