### 解题思路
递归查询树的左右节点深度，返回最大的值

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
    public int maxDepth(TreeNode root) {
        int depth = 0;
        if(root == null){
            return depth;
        }else{
            depth+=1;
        }
        return depth + Math.max(maxDepth(root.left),maxDepth(root.right));

    }
}
```