### 解题思路
先来一个模板：
二叉树算法的设计的总路线：明确一个节点要做的事情，然后剩下的事就抛给框架。
```java
    void traverse(TreeNode root) {
        // root 需要做什么？在这做。
        // 其他的不用root操心，抛给框架
        traverse(root.left);
        traverse(root.right);
    }
```
编写思路：
    1.根据模板我要拿到最后解，我去找我的两个子树，左子树和右子树于是有：
 ```java
    递归的从左子树中去找是否存在我要的解：hasPathSum(root.left, sum - root.val)
    递归的从右子树中去找是否存在我要的解：hasPathSum(root.right, sum - root.val)
    于是核心： return hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val);稳重的落地！！
```
    2.接着就要找本题的边界了
    注意：本题是根节点到叶子节点，我的错误就是没有看清楚题目，必须到**叶子节点**！
    于是有一个边界为：
    root！=null && root.left == null && root.right == null 表示root为叶子节点于是加上最后一个条件root.val == num是一个边界
```
if ( root.left == null && root.right == null && root.val == sum )
            return true;
```


![image.png](https://pic.leetcode-cn.com/b871be854b9a016864a1ee01dcfec31b4555b5fa3750199c54934e73171e146a-image.png)

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
    public boolean hasPathSum(TreeNode root, int sum) {
        // 当节点已经不在树中了，仍然没有返回true说明，该路没有所要的解
        if ( root == null )
            return false;
        // root节点的左右孩子都为null说明该节点是叶子节点
        if ( root.left == null && root.right == null && root.val == sum )
            return true;

        return hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val);
    }
}
```