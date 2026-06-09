# 解法思路（一）
- 如果 p 和 q 在 root 的两边，那么 root 就是 p 和 q 的最低的公共祖先，这种情况包含三种具体的情况：
  - p 和 q 在 root 的两边；
  - p 就是 root，q 在 root 的哪边不所谓；
  - q 就是 root，p 在 root 的哪边不所谓；
- 如果不是上面的情况，p 和 q 要么全在 root 的左边，要么全在 root 的右边，这时只需递归的去 root 的左子树或右子树中找 p 和 q 的最低公共祖先；

# 解法实现（一）
###### 时间复杂度
- O(logN)，其中 N 为树的节点个数；
###### 空间复杂度
- O(h)，其中 h 为树的高度；
###### 关键字
`二分搜索树` `递归` `二分搜索树中节点的公共祖先`
###### 实现细节
- 注意 `return root` 时包含的三种情况；
- 这道题包含的二分搜索树的性质很有意思；
```
package leetcode._235;

public class Solution235_1 {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        assert p != null && q != null;

        if (p.val < root.val && q.val < root.val) {
            return lowestCommonAncestor(root.left, p, q);
        }
        if (p.val > root.val && q.val > root.val) {
            return lowestCommonAncestor(root.right, p, q);
        }

        assert p.val == root.val || q.val == root.val
                || (root.val - p.val) * (root.val - q.val) < 0;

        return root;
    }

}
```
[返回 LeetCode [Java] 目录](https://www.jianshu.com/p/2cc66577f7d7)