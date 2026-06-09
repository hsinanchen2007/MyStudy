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
    public int maxDepth(TreeNode root) {
        if(root==null){
            return 0;
        }
        int lefTreetHight =  maxDepth(root.left);
        int rightTreeHight = maxDepth(root.right);
        return lefTreetHight > rightTreeHight ? lefTreetHight + 1:rightTreeHight + 1;
    }
}
```