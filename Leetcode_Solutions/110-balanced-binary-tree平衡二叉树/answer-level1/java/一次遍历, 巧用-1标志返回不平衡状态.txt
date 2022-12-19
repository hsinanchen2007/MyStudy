### 解题思路

主要是利用平衡树的性质,只要有子树不平衡,则次树不平衡.
通过递归遍历 同时得到树的深度及它的平衡状态,
如果平衡,则返回它的深度, 不平衡,则返回-1

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
    // 定义 -1 为不平衡的标志, 如果不平衡返回-1, 平衡的话返回树的深度
    public int depth(TreeNode root){
        if(root == null)
            return 0;
        
        int left_depth = depth(root.left);
        int right_depth = depth(root.right);
        int depth;
        // 如果左树或者右树不平衡, 或者当前树不平衡, 把不平衡的状态一直返回
        if(left_depth == -1 || right_depth == -1 || Math.abs(left_depth - right_depth)>1)
            depth = -1;
        else{
        // 如果当前树 及其 左右子树均平衡, 则返回当前树的深度, 返回上一层再比较
            depth = Math.max(left_depth, right_depth) + 1;
        }
        return depth;
    }

    public boolean isBalanced(TreeNode root) {
        if(root == null)
            return true;
        
        if(depth(root) == -1)
            return false;
        return true;

    }
}
```