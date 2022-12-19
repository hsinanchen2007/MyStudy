# 解题思路
**题目前提说明：**
- 所有节点的值都是唯一的。
- p、q 为不同节点且均存在于给定的二叉树中。

**二叉树公共节点的三种情况：**

1. p 和 q 都在左子树 ( right == null 或 left != null)
3. p 和 q 都在右子树 ( left == null 或 right !=null)
4. p 和 q 一个在左子树 一个在右子树 那么当前节点为最近公共祖先

- 情况1：如果右子树找不到 p 或 q 即(right==null)，那么说明 p 和 q 都在左子树上，返回 left 
        
- 情况2：如果左子树找不到 p 或 q 即(left==null)，那么说明 p 和 q 都在右子树上，返回 right
        
- 情况3：如果上述情况都不符合，说明 p 和 q 分别在左子树和右子树，那么当前节点即为最近公共祖先，直接返回 root 即可。

---

# 递归

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
     	//返回节点存在情况
        if(root == null || p == root || q ==root)
            return root;
        //再左右子树寻找 p q 两个节点
        TreeNode left = lowestCommonAncestor(root.left,p,q);
        TreeNode right = lowestCommonAncestor(root.right,p,q);
        //情况1：如果右子树找不到 p 或 q 即(right==null)，
        //那么说明 p 和 q 都在左子树上，返回 left 
        
        //情况2：如果左子树找不到 p 或 q 即(right==null)，
        //那么说明 p 和 q 都在右子树上，返回 right
        
        //如果上述情况都不符合，说明 p 和 q 分别在左子树和右子树，
        //那么最近公共节点为当前节点
        //直接返回 root 即可
        return (right == null) ? left : (left == null) ? right : root;
    }
}
```
---