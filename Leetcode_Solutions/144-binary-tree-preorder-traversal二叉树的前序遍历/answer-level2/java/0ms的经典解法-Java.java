### 解题思路
经典无需多言

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

    public List<Integer> preorderTraversal(TreeNode root) {
        if (root == null) {
            return list;
        }
        preSearch(root);
        return list;
    }

    private void preSearch(TreeNode root) {
        if (root == null) {
            return;
        }
        list.add(root.val);
        preSearch(root.left);
        preSearch(root.right);
    }
}
```