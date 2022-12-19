### 解题思路
![1325.删除给定值的叶子节点.png](https://pic.leetcode-cn.com/e4394cafc668faa0a6529647b95002e8dd69ac141b31a69e93381994e93dea7c-1325.%E5%88%A0%E9%99%A4%E7%BB%99%E5%AE%9A%E5%80%BC%E7%9A%84%E5%8F%B6%E5%AD%90%E8%8A%82%E7%82%B9.png)

利用深度优先（后序遍历），每次递归的时候传的参数有两个，一个是当前节点，一个是当前节点的父节点

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

    int tar;

    public TreeNode removeLeafNodes(TreeNode root, int target) {
        tar = target;
        helper(null, root);
        if(root.val == target && root.left == null && root.right == null)
            return null;
        return root;
    }

    private void helper(TreeNode father, TreeNode node) {
        if(node == null) return;

        helper(node, node.left);
        helper(node, node.right);

        //如果这个节点是叶子节点，并且这个叶子节点的值是要删除的值，这个叶子节点父节点不为null（这个节点不是根节点）
        if(node.left == null && node.right == null && node.val == tar && father != null) {
            if(father.left == node) father.left = null;
            else father.right = null;
        }
    }
}
```