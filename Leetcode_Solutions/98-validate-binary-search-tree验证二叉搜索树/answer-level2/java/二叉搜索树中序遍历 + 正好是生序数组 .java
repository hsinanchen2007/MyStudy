### 解题思路
利用中序遍历的特点

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
    //二叉搜索树 定义 其中序遍历是递增的
    
    TreeNode pre = null;//保存中序遍历的前一个值

    public boolean isValidBST(TreeNode root) {
         
         if (root == null) {
             return true;
         }

         //左子树
         if (!isValidBST(root.left))  return false;

         //遍历到中间节点
         if (pre != null && pre.val >= root.val) return false;

         //赋值到下一位
         pre = root;

         //递归右节点值
         return isValidBST(root.right);

    }
    
}
```