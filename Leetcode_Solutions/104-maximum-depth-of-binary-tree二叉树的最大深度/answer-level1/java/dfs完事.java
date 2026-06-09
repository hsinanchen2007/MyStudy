### 解题思路
dfs

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
        return dfs(root,0);
    }
    public int dfs(TreeNode node,int height){
        if(node==null){
            return height;
        }
        int leftHeight=dfs(node.left,height+1);
        int rightHeight=dfs(node.right,height+1);
        return Math.max(leftHeight,rightHeight);
    }
}
```