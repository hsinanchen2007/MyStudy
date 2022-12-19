### 解题思路
递归体分三种情况讨论：

1. 如果p和q分别是root的左右节点，那么root就是我们要找的最近公共祖先
1. 如果p和q都是root的左节点，那么返回lowestCommonAncestor(root.left,p,q)
1. 如果p和q都是root的右节点，那么返回lowestCommonAncestor(root.right,p,q)

边界条件讨论：

1. 如果root是null，则说明我们已经找到最底了，返回null表示没找到
1. 如果root与p相等或者与q相等，则返回root
1. 如果左子树没找到，递归函数返回null，证明p和q同在root的右侧，那么最终的公共祖先就是右子树找到的结点
1. 如果右子树没找到，递归函数返回null，证明p和q同在root的左侧，那么最终的公共祖先就是左子树找到的结点

 
[原题解地址](https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/jian-dan-yi-dong-xiang-jie-ru-xia-by-yuanninesuns/)
 

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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == p || root == q || root == null)
            return root;
        TreeNode leftnode = lowestCommonAncestor(root.left, p, q);
        TreeNode rightnode = lowestCommonAncestor(root.right, p, q);
        if (leftnode == null)
            return rightnode;
        if (rightnode == null)
            return leftnode;
        return root;
    }
}
```