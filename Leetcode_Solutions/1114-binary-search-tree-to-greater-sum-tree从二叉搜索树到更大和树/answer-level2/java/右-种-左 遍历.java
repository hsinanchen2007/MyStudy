### 解题思路
右中左遍历，逆序左右的val值，然后累加起来就好。

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
    public TreeNode bstToGst(TreeNode root) {
        int sum = 0;
        TreeNode temp = root;
        if (root == null)
            return root;
        List<TreeNode> list = new ArrayList<>();
        while (list.size() != 0 || root != null){
            if (root != null){
                list.add(root);
                root = root.right;
            }
            else {
                TreeNode remove = list.remove(list.size() - 1);
                remove.val = remove.val + sum;
                sum = remove.val;
                root = remove.left;
            }
        }
        return temp;
    }
}
```