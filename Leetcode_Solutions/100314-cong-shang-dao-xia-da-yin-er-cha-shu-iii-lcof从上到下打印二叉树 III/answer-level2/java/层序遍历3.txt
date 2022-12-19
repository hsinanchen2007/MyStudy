### 解题思路

使用两个stack来实现，使用stack的先进后出特性即可实现题目要求，但是需要特别注意的一点是，当需要从左往右输出的时候，要按照右子树 -> 左子树的顺序放（因为栈先进后出）


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
        if (root == null) {
            return Collections.emptyList();
        }
        List<List<Integer>> ll = new ArrayList<>();
        Deque<TreeNode> queue = new LinkedList<>();
        Deque<TreeNode> swapQueue = new LinkedList<>();
        boolean reverse = false;

        // 压入根节点
        queue.push(root);
        while (!queue.isEmpty() || !swapQueue.isEmpty()) {
            // 掏空一层
            Deque<TreeNode> level, next;
            if (queue.isEmpty()) {
                level   = swapQueue;
                next    = queue;
            } else {
                level   = queue;
                next    = swapQueue;
            }
            List<Integer> levelList = new ArrayList<>();
            while (!level.isEmpty()) {
                // 取出当前节点
                TreeNode cur = level.removeFirst();
                levelList.add(cur.val);

                // 压入下一层
                if (reverse) {
                    if (cur.right != null) {
                        next.addFirst(cur.right);
                    }
                    if (cur.left != null) {
                        next.addFirst(cur.left);
                    }
                } else {
                    if (cur.left != null) {
                        next.addFirst(cur.left);
                    }
                    if (cur.right != null) {
                        next.addFirst(cur.right);
                    }
                }
            }
            // 结束一层
            ll.add(levelList);

            // 下一层开始翻转
            reverse = (!reverse);
        }
        return ll;
    }
}
```