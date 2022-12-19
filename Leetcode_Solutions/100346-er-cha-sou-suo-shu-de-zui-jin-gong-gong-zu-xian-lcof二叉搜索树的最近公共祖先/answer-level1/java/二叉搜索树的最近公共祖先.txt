### 解题思路
二叉搜索树根节点始终大于左子树小于右子树，因此存在三种情况
一：一个节点小于根节点，一个节点大于根节点---两个节点位于根节点两侧
二：两个节点位于根节点同侧：判断是左侧还是右侧，进入
三：其中一个节点等根节点
其中，一和三均需要返回根节点
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
        if(root.val>p.val&&root.val>q.val){
            return lowestCommonAncestor(root.left, p, q);
        }else if(root.val<p.val&&root.val<q.val){
             return lowestCommonAncestor(root.right, p, q);
        }
        return root;
        
    }
}
```