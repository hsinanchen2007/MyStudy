### 解题思路
此处撰写解题思路

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
        isBST(root, list);
        for (int i = 1; i < list.size(); i++) {
            if (list.get(i - 1).compareTo(list.get(i)) >= 0) {
                return false;
            }
        }
        return true;
    }
    private void isBST(TreeNode root, List<Integer> list) {
        if (null == root) {
            return;
        }
        isBST(root.left, list);
        list.add(root.val);
        isBST(root.right, list);
    }
}

```