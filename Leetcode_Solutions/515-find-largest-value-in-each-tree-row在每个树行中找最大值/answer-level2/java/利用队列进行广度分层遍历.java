### 解题思路
此处撰写解题思路

利用队列进行广度分层遍历， 同分层遍历

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
    public List<Integer> largestValues(TreeNode root) {
        if (root == null) {
            return Collections.emptyList();
        }

        List<Integer> result = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (queue.size() > 0) {
            int size = queue.size();
            int lineMax = queue.peek().val;
            while (size-- > 0) {
                TreeNode node = queue.poll();
                if (lineMax <= node.val) {
                    lineMax = node.val;
                }
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
            //遍历完当前层，将最大值添加到列表
            result.add(lineMax);
        }

        return result;
    }
}
```