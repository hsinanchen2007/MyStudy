### 解题思路
找二叉树的最近公共祖先可以转化为找两个结点所在子树的根，那么可以分3种情况：
1.p是q的根，或q是p的根，直接返回
2.p、q处在root的左子树或右子树，递归求子树，时间复杂度为对数级别
3.p、q处于不同的子树，root即是最近公共祖先
时间复杂度：O(lgn)
空间复杂度：O(n),递归性能最差时可能在调用栈上存了所有的结点
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
        if(root == null)
            return root;
        if(findNode(p,q))
        return p;
        if(findNode(q,p))
        return q;
        if(findNode(root.left,p) && findNode(root.left,q)){
            return lowestCommonAncestor(root.left,p,q);
        }
        if(findNode(root.right,p) && findNode(root.right,q))
            return lowestCommonAncestor(root.right,p,q);
        return root;
    }

    private boolean findNode(TreeNode root, TreeNode p){
        if(root == null)
            return false;
        if(root == p)
            return true;
        if(root.left != null)
            if(findNode(root.left,p))
                return true;
        return findNode(root.right,p);
    }
}
```