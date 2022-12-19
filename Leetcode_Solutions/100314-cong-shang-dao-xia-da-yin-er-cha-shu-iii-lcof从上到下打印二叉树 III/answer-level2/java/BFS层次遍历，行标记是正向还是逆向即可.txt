### 解题思路
层次遍历，增加一个行标记，当前层遍历完成，改变标记，上一层是正向，这一层就是逆向，迭代BFS即可

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
            return new ArrayList<>();
        }
        List<List<Integer>> level = new ArrayList<>();
        LinkedList<Integer> everyLevel = new LinkedList<>();
        TreeNode node = root;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(node);
        int rear = queue.size();// 队尾标记
        boolean flag = true;// true表示正向，false表示反向
        while (!queue.isEmpty()) {
            node = queue.poll();
            if (flag)
                everyLevel.add(node.val);
            else
                everyLevel.addFirst(node.val);
            rear--;// 队列长度-1
            if (node.left != null) {
                queue.offer(node.left);
            }
            if (node.right != null) {
                queue.offer(node.right);
            }
            if (rear == 0){// 当前层遍历结束
                level.add(everyLevel);
                everyLevel = new LinkedList<>();
                rear = queue.size();
                flag = !flag;
            }
        }
        return level;
    }
}
```