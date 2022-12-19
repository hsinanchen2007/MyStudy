### 解题思路
递归算法，利用二分搜索树性质，当前节点值大于val找左节点，小于找右节点，等于直接返回

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
        return helper(root,val);
    }
    private TreeNode helper(TreeNode node,int val){
        if (node==null)
            return null;
        else if (node.val==val)
            return node;
        if (node.val>val)
            return helper(node.left,val);
        else
            return helper(node.right,val);
    }
}
```