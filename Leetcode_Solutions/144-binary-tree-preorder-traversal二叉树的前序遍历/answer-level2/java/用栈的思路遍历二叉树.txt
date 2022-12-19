### 解题思路
二叉树是从数据结构课开始接触的，宋文老师讲过用栈的方式解决遍历，转眼毕业6年了，感恩的心！

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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        result.add(root.val);
        TreeNode L = root.left;
        TreeNode R = root.right;
        List<TreeNode> list = new ArrayList<>();
        if (R != null) {
            list.add(R);
        }
        if (L != null) {
            list.add(L);
        }
        while (list.size() > 0) {
            TreeNode n = list.remove(list.size() - 1);
            result.add(n.val);
            if (n.right != null) {
                list.add(n.right);
            }
            if (n.left != null) {
                list.add(n.left);
            }
        }
        return result;
    }
}
```