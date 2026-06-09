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
    int maxDepth;
    int result;
    public int findBottomLeftValue(TreeNode root) {
        dfs(root,1);
        return result;
    }
    public void dfs(TreeNode root,int depth){
        if(root==null){
            return;
        }
        if(depth>maxDepth){
            result=root.val;
            maxDepth=depth;
        }
        dfs(root.left,depth+1);
        dfs(root.right,depth+1);
    }
}
```