### 解题思路
本题是一个典型的递归题，可以看出遍历顺序应当为为右子树，根节点，左子树。其中每 遍历到当前元素的值应该是上一元素的值加上当前元素的值。这里采用全局变量记录上一元素的值。

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
    public int sum=0;
    public TreeNode bstToGst(TreeNode root) {
        if(root==null)
            return null;
        bstToGst(root.right);
        root.val=root.val+sum;
        sum=root.val;
        bstToGst(root.left);
        return root;
    }
}
```