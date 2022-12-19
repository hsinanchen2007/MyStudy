### 解题思路
很简单的后序遍历，只是在递归的时候要附带上父节点，这样方便剪枝

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
    public TreeNode pruneTree(TreeNode root) {
        helper(null, root);
        //如果剪枝完的树只有一个值为0的节点，直接就返回空即可
        if(root.val == 0 && root.left == null && root.right == null) return null;
        return root;
    }

    private void helper(TreeNode father, TreeNode node){
        if(node == null) return;

        helper(node, node.left);
        helper(node, node.right);

        if(node.val == 0) {
            //如果父节点为null的话，那么一定是根节点，直接返回即可
            if(father == null) return;
            //如果这个节点是叶子节点，那么直接就剪掉这个节点就可以了
            if(father.left == node && node.left == null && node.right == null) father.left = null;
            else if(father.right == node && node.left == null && node.right == null) father.right = null;
        }
    }
}
```