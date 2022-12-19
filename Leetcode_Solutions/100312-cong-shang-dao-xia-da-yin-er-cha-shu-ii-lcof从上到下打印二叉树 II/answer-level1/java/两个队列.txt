### 解题思路

使用两个队列来搞，当前队列和下一层队列，取的时候从当前队列取，然后将当前队列的子树放到下一层节点队列里面，循环，知道两个队列都为空；


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
                TreeNode cur = level.removeLast();
                levelList.add(cur.val);
                
                // 压入下一层
                if (cur.left != null) {
                    next.addFirst(cur.left);
                }

                if (cur.right != null) {
                    next.addFirst(cur.right);
                }
            }
            // 结束一层
            ll.add(levelList);
        }
        return ll;
    }
}
```