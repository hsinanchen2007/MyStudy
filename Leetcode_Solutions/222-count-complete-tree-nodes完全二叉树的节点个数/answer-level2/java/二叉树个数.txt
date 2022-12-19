### 解题思路
判断二叉树节点多少的递归判断方式。

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

    public int getNodeNumber(TreeNode root){
        if(root == null)
            return 0;
        return getNodeNumber(root.left) + getNodeNumber(root.right) + 1;
    }

    public int countNodes(TreeNode root) {
        return getNodeNumber(root);
    }
}
```