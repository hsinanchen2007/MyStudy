### 解题思路
利用搜索二叉树的性质分为3种情况
1 如果根节点的值等于val，则直接返回根节点
2 如果根节点的值大于val，那么要找的子二叉树必然在左子树中。
3 如果根节点的值小于val，那么要找的子二叉树必然在右子树中。
递归以上3种情况。

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
    public TreeNode searchBST(TreeNode root, int val) {
     if(root==null) return null;
     if(root.val<val) return searchBST(root.right,val);
     else if(root.val>val) return searchBST(root.left,val);
     else if(root.val==val) return root;  
     return null; 
    }
}
```