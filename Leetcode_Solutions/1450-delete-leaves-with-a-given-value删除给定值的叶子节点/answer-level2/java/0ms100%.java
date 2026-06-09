### 解题思路
递归
如果当前节点与target一致而且为叶子节点，则返回null，否则返回此节点

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
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        return helper(root,target);
    }
    private TreeNode helper(TreeNode node,int target){
        if (node==null)
            return null;

        node.left=helper(node.left,target);
        node.right=helper(node.right,target);
        if (node.val==target && node.left==null && node.right==null)
            return null;
        else 
            return node;
    }
}
```