### 解题思路
这个题目主要是需要研究明白递归时，传递给left以及right的变量，总体的规则就是
node=left upper=self lower=lower
node=right upper=upper lower=self

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
    public boolean isValidBST(TreeNode root) {
        return isValidBSTHelper(root, null,null);
    }

    public boolean isValidBSTHelper(TreeNode root, Integer upper, Integer down) {
        if (root == null) return true;
        if (upper != null && root.val >= upper ) return false;
        if (down != null && root.val <= down ) return false;
        if (!isValidBSTHelper(root.left, root.val, down)) return false;
        if (!isValidBSTHelper(root.right, upper, root.val)) return false;
        return true;
    }
}
```