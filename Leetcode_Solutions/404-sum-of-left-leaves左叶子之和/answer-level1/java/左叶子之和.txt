### 解题思路
    求取二叉树左子树之和，那么可以递归求取。首先判断它是不是左叶子节点，如果是则加进去
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
    public int sumOfLeftLeaves(TreeNode root) {
       //其实就是判断这个节点是不是左叶子节点，如果是才将它加起来
       int sum=0;
       if(root==null)
         return 0;
        if(root.left!=null&&root.left.left==null&&root.left.right==null)
            sum+=root.left.val;
        return sumOfLeftLeaves(root.left)+sumOfLeftLeaves(root.right)+sum;
    }
}
```