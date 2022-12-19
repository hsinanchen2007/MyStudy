### 解题思路
DFS+条件判断  终止条件是当到达叶子节点 sum-叶子节点的值刚好等于0表示已经找到,还有如果根节点或者当前节点为null返回false,之后就是分别遍历左子树或者右子树

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
        if(root==null)
        {
            return false;
        }
        
        if(root.left==null && root.right==null && sum-root.val==0)
        {
            return true;
        }
        
        return hasPathSum(root.left,sum-root.val) || 
                hasPathSum(root.right,sum-root.val);
    }
}
```