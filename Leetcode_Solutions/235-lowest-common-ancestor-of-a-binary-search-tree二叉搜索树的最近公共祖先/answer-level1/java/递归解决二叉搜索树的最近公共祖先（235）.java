### 解题思路
利用二叉搜索树的性质可以很容易解出来。
有个点是不需要找到那个结点，只需要符合**当前结点的值在给出的两个结点之间**就行。在这个地方卡了下，对二叉搜索树的性质掌握的还不够，加油！

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
        // 以下四行可以减少执行时间，不加也可以通过
        if(root.val == p.val)
            return p;
        if(root.val == q.val)
            return q;
        if(root.val > p.val && root.val > q.val)
            return lowestCommonAncestor(root.left, p, q);
        else if(root.val < p.val && root.val < q.val)
            return lowestCommonAncestor(root.right, p, q);
        else
            return root;
    }
}
```