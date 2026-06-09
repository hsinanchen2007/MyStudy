### 解题思路
deque, 从左往右时，deque.addLast(); 从右往左时，deque.addFirst()

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ret = new ArrayList();
        if (root == null) {
            return ret;
        }
        Deque<TreeNode> queue = new LinkedList();
        queue.add(root);
        boolean left = true;
        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> list = new ArrayList();
            for (int i = 0; i < size; i++) {
                if (left) {
                    TreeNode cur = queue.removeFirst();
                    list.add(cur.val);
                    if (cur.left != null) queue.addLast(cur.left);
                    if (cur.right != null) queue.addLast(cur.right);
                } else {
                    TreeNode cur = queue.removeLast();
                    list.add(cur.val);
                    if (cur.right != null) queue.addFirst(cur.right);
                    if (cur.left != null) queue.addFirst(cur.left);
                }
            }
            left = !left;
            ret.add(list);
        }
        return ret;
    }
}
```