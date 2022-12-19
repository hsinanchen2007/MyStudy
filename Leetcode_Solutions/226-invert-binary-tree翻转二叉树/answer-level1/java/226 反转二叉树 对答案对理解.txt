### 解题思路

代码是lc答案的代码
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
    public TreeNode invertTree (TreeNode root) {
        if (root == null) 
            return null;
        TreeNode right = invertTree(root.right);
        TreeNode left = invertTree(root.left);
        root.left = right;
        root.right = left;
        return root;
    }
}
```
下面是用一个简答的例子帮助自己理解

![IMG_0038.jpg](https://pic.leetcode-cn.com/4fcb9c7969717359ea51faddb90ec1718f57b285115557e74367dedf7d7e1597-IMG_0038.jpg)



