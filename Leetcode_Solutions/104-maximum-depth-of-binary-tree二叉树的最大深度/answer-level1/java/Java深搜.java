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
    int  max = Integer.MIN_VALUE;
    public int maxDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        dfs(root,0);
        return max;
    }
    public void dfs(TreeNode root,int h){
        h++;
        if(root.left != null){
            dfs(root.left,h);
        }
        if(h > max){
            max = h;
        }
        if(root.right != null){
            dfs(root.right,h);
        }
        h--;
    }
}
```