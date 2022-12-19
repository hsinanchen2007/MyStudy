### 解题思路
中序遍历后，看是否是递增的

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
        List<Integer> list = new ArrayList<>();
        zxblBst(root, list);
        for (int i = 1; i < list.size(); i++) {
            if (list.get(i - 1) >= list.get(i)) {
                return false;
            }
        }
        return true;
    }

    private void zxblBst(TreeNode root, List<Integer> list) {
        if (root == null) {
            return;
        }
        zxblBst(root.left, list);
        list.add(root.val);
        zxblBst(root.right, list);
    }
}
```