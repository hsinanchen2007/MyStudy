### 解题思路
递归找树的深度即可

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
    public int minDepth(TreeNode root) {
        return dfs(root, 0);
    }

    public int dfs(TreeNode node, int height){
        if (node == null) {
            return height;
        }
        int heightLeft=Integer.MAX_VALUE;
        int heightRight = Integer.MAX_VALUE;
        if(node.left == null && node.right == null){
            return height+1;
        }
        if (node .left != null){
            heightLeft = dfs(node.left,height+1);
        }
        if (node .right != null){
            heightRight = dfs(node.right,height+1); 
        }
        if(heightRight < heightLeft){
            return heightRight;
        }
        return heightLeft;
    }
}
```