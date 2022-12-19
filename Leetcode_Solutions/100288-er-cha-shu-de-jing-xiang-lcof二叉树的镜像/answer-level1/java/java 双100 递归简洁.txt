### 解题思路
![image.png](https://pic.leetcode-cn.com/253115a2388e8af4952facd1525a6efc8f0aba384536fd572b3265cb238c1086-image.png)


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
        if(root==null) return null;
        TreeNode t = mirrorTree(root.left);
        root.left = mirrorTree(root.right);
        root.right = t;
        return root;

    }
}
```