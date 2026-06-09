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
    boolean findFlag = false;
    TreeNode res = null;
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        
        if(root == null || res != null)
            return res;
        TreeNode left = inorderSuccessor(root.left, p);
        if(root == p){
            findFlag = true;
        }else if(findFlag){
            res = root;
            findFlag = false;
        }
        TreeNode right = inorderSuccessor(root.right, p);
        return res;
    }
    
   
}
```