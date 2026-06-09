### 解题思路
由题意可看出，将树反过来看，中序遍历修改值即可

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
    int pre = 0;
    public TreeNode bstToGst(TreeNode root) {
        if (root == null) {
            return null;
        }
        bstToGst(root.right);
        root.val = pre + root.val;
        pre = root.val;
        bstToGst(root.left);
        return root;
    }

}
```