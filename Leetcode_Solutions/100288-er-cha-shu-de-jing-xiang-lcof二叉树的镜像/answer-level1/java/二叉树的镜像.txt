### 解题思路
此处撰写解题思路

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
        if(root==null)
            return null;
        //交换左右子树
        TreeNode node=root.left;  //防止找不到镜像
        root.left=mirrorTree(root.right);
        root.right=mirrorTree(node);
        return root;
    }
}
```