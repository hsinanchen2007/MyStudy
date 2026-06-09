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
    public boolean isSymmetric(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList();
        //queue存放上一层的节点
        queue.offer(root);
        while (queue.size() > 0 && !isAllNull(queue)) {
            int size = queue.size();
            int[] values = new int[size];
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                if (node != null) {
                    values[i] = node.val;
                } else {
                    values[i] = Integer.MIN_VALUE;
                }
                if (node != null) {
                    queue.add(node.left);
                    queue.add(node.right);
                } else {
                    queue.add(null);
                    queue.add(null);
                }
            }
            int half = values.length / 2;
            for (int i = 0; i < half; i++) {
                if (values[i] != values[values.length -1 - i]) {
                    return false;
                }
            }
        }
        return true;
    }

    boolean isAllNull(Queue<TreeNode> queue) {
        Iterator<TreeNode> it = queue.iterator();
        while (it.hasNext()) {
            if (it.next() != null) {
                return false;
            }
        }
        return true;
    }
}
```