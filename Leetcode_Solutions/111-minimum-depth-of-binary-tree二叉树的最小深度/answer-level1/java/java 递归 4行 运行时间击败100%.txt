### 解题思路
递归的思路
找到终止条件： root==null; return 0;
递归函数：
    2中情况：a：左右子树其中一个为null，见第二三行；b:左右子树都为空或都不为空，第四行

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
        if(root == null) return 0;
        if(root.right == null&& root.left!=null) return minDepth(root.left)+1;
        if(root.left ==null&& root.right!=null)  return minDepth(root.right)+1;
        return Math.min(minDepth(root.left),minDepth(root.right))+1;
    }
}
```