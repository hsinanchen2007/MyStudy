### 解题思路
1 left为NULL，因为题目保证有解，所以答案必在右边
2 left不为NULL，则看right是否为NULL，若right为NULL， 则答案一定是左边这个left。
3 左右都不为NULL， 说明root在中间，p和q在两边。该根结点一定是最近公共祖先。

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
    * 递归，(毕竟要找公共根节点)。
    **/
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // 1 找到对应的p，q
        if (root == null || root == p || root == q) return root;
        // 2 递归左右节点
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        // 3 判空返回 
        if (left == null) return right;
        if (right == null) return left;
        return root;
    }
}
```