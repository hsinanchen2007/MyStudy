### 解题思路
一个树是平衡二叉树，则它的根节点是平衡节点，左右节点也是平衡节点
合理利用递归
如果左右子树深度相差不大于1的条件放在最后判断，用时3ms
放在最前判断，可以有效减少计算量，用时1ms。

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
    public boolean isBalanced(TreeNode root) {
        if (root != null){
            return Math.abs(depth(root.left) - depth(root.right)) <= 1
            && isBalanced(root.left)
            && isBalanced(root.right);
        }else{
            return true;
        }
    }

    public int depth(TreeNode root){
        if(root == null){
            return 0;
        }else{
            return Math.max(depth(root.left), depth(root.right)) + 1;
        }
    }
}
```