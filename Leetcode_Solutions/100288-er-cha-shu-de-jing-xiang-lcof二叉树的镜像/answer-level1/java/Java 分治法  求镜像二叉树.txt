### 解题思路
   

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
    public TreeNode mirrorTree(TreeNode root) {
        if(root ==null){
            return null;
        }
        //divide
        TreeNode left = mirrorTree(root.left);
        TreeNode right = mirrorTree(root.right);

        //conquer
        root.left=right;
        root.right=left;

        return root;


    }
}
```