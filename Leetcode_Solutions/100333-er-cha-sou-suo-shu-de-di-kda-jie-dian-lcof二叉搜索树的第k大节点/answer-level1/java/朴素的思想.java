### 解题思路
中序遍历即是有序的，旋转一下即可得到第K大的。

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
    List<Integer> list = new ArrayList<>();

    public int kthLargest(TreeNode root, int k) {
        if (root == null) {
            return 0;
        }
        mid(root);
        Collections.reverse(list);
        return list.get(k - 1);
    }

    private void mid(TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.left != null) {
            mid(root.left);
        }
        list.add(root.val);
        if (root.right != null) {
            mid(root.right);
        }
    }
}
```