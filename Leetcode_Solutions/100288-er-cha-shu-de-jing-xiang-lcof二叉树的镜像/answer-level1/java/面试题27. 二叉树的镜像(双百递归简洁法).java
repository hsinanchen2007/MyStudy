### 解题思路
主要思路：
1.判空树
2.判断该节点是否是叶子节点
3.交换左右子树
4.递归左右子树

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
    public TreeNode mirrorTree(TreeNode root) {
        if(root==null)return null;
        if(root.left==null&&root.right==null)return root;
        TreeNode item=root.left;
        root.left=root.right;
        root.right=item;
        if(root.left!=null)mirrorTree(root.left);
        if(root.right!=null)mirrorTree(root.right);
        return root;
    }
}
```