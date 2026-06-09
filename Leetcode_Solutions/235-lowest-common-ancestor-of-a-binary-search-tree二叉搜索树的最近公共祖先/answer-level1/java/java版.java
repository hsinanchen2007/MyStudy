### 解题思路
递归
利用搜索二叉树的性质分为3中情况：
1 根节点的值大于p,q节点的值则说明最近公共祖先在左子树上。
2 根节点的值小于p，q节点的值则说明最近公共祖先在右子树上。
3 根节点的值在p，q之间则说明最近公共祖先为根节点。


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
        //if((p.val<root.val)&&(q.val<root.val)||(q.val<root.val)&&(p.val<root.val)) return root;
        if((p.val<root.val)&&(q.val<root.val)) {return lowestCommonAncestor(root.left,p,q);}
        else if((p.val>root.val)&&(q.val>root.val))  {return lowestCommonAncestor(root.right,p,q);}else{
            return root;
        }
    }
}
```