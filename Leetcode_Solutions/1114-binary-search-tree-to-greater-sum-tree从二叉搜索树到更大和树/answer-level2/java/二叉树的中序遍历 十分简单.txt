### 解题思路
中序遍历 区别在于 先遍历右侧 
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
    int total = 0;
    //二叉搜索树 中序遍历
    public TreeNode bstToGst(TreeNode root) {
        if(root == null){
            return null;
        }
        bstToGst(root.right);
        total+=root.val;
        root.val = total;
        bstToGst(root.left);
        return root;
    }
}
```