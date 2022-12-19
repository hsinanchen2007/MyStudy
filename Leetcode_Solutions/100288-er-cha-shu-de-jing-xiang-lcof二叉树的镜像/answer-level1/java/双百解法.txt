### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/cc4f5c19f5ee298fac989f31e41c3db18beb916b148571fe039d775ee6ea7cbe-image.png)
递归如此轻松
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
        if(root==null){
            return null;
        }
        TreeNode left = mirrorTree(root.left);
        TreeNode right = mirrorTree(root.right);
        root.left = right;
        root.right = left;
        return root;
    }
}
```