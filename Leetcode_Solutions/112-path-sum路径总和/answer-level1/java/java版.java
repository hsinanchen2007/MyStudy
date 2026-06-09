### 解题思路
1 递归遍历左右子树，每次遍历的sum值等于前一次sum值减去上一次遍历的父节点的值。
2 直到遍历的叶子结点，当叶子结点的值和当前sum的值相等的时候说明存在这个路径。

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
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null) return false;
        if((root.right==null)&&(root.left==null)){
            return(sum==root.val);
        }
        return hasPathSum(root.left,sum-root.val)||hasPathSum(root.right,sum-root.val);
    }
}
```