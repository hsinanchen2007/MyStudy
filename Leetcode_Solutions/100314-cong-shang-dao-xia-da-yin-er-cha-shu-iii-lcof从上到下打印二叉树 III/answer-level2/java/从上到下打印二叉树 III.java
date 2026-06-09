### 解题思路
还是层序遍历，只不过集合要放到list大集合之前先reverse一下

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
            return new ArrayList<>(10);
        }
        List<List<Integer>> list = new ArrayList<>(10);
        // 借助一个队列来做层序遍历
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int counter = 1;
        while (!queue.isEmpty()) {
            int len = queue.size();
            List<Integer> item = new ArrayList<>(10);

            for (int i = 0; i < len; i++) {
                TreeNode node = queue.poll();
                item.add(node.val);
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
            if (counter++ % 2 == 0) {
                Collections.reverse(item);
            }
            list.add(item);
        }

        return list;
    }
}
```