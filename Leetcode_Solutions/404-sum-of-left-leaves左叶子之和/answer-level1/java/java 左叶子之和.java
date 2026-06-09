### 解题思路
遍历二叉树的非叶子节点，当左叶子存在时，求和。

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
    private int sum=0;
    public int sumOfLeftLeaves(TreeNode root) {
        if(root==null) return 0;
        //判断左叶子是否存在
        if(root.left!=null&&root.left.left==null&&root.left.right==null)
            sum+=root.left.val;
        //遍历二叉树非叶子节点
        if(root.left!=null&&(root.left.left!=null||root.left.right!=null))
            sumOfLeftLeaves(root.left);
        if(root.right!=null&&(root.right.left!=null||root.right.right!=null))
            sumOfLeftLeaves(root.right);

        return sum;
    }
}
```