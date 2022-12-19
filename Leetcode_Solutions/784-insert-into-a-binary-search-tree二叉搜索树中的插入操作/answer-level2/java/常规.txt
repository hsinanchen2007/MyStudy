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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if(root == null) return new TreeNode(val);
        dfs(root,val);
        return root;
    }
    private void dfs(TreeNode root, int val){
        if(root.val > val){
            if(root.left == null){
                root.left = new TreeNode(val);
                return;
            }else
                dfs(root.left, val);
        }else{
            if(root.right == null){
                root.right = new TreeNode(val);
                return;
            }else
                dfs(root.right, val);
        }
    }
}
```