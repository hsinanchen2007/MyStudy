### 解题思路
思路与求子树深度类似
只需要注意一点，左右子树至少有一个为空时，mindepth = mindepth(left)+mindepth(right)+1;
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
    public int minDepth(TreeNode root) {
        if(root == null)
        return 0;
        if(root.left!=null&&root.right!=null)
        return Math.min(minDepth(root.left),minDepth(root.right))+1;
        else 
        return minDepth(root.left)+minDepth(root.right)+1;
    }
}
```