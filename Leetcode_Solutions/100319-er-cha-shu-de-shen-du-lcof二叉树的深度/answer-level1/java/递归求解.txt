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
        int leftHight = maxDepth(root.left);
        int rightHeight = maxDepth(root.right);
        return leftHight > rightHeight ? leftHight + 1 : rightHeight + 1;
    }
}
```