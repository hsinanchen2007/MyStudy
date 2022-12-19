### 解题思路
最近公共祖先有三种情况：
    1 两个节点分别在根节点的左右子树上，那么此时最近公共祖先为根节点
    2 两个节点都在左子树上，那么最近公共最先也必然在左子树上
    3 两个节点都在右子树上，那么最近公共最先也必然在右子树上
注意：
公共祖先有可能为节点本身。

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
        if(root==null) return null;
        if(root==p||root==q) return root;
        TreeNode left=lowestCommonAncestor(root.left,p,q);
        TreeNode right=lowestCommonAncestor(root.right,p,q);
        if(left!=null&&right!=null) return root;//最近公共祖先为根节点
        if(left!=null) return left;//最近公共祖先在左子树上
        if(right!=null) return right;//最近公共祖先在右子树上

        return null;
    }  
}
```