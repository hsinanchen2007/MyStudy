### 解题思路
使用中序遍历，加入到一个list集合中，每一次要添加的节点值必须大于list中最后一个节点的值，否则返回false

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
        if (root == null) return true;
        LinkedList<Integer> list = new LinkedList<>();
        return find(root, list);
    }
    private static boolean find(TreeNode root, LinkedList<Integer> list) {
        if (root != null) {
            int v = root.val;
            return find(root.left, list) && (list.isEmpty() && list.add(v) || !list.isEmpty() && (list.getLast() < v) && list.add(v)) && find(root.right, list);
        }
        return true;
    }
}
```