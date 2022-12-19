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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) return res;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        // 记录搜索的层数，用于控制遍历的顺序
        int level = 1;
        while (!queue.isEmpty()) {
            int size = queue.size();
            LinkedList<Integer> list = new LinkedList<>();
            // 如果 level 是奇数，则从左往右遍历，否则从右往左
            boolean fromLeft = level % 2 == 1;
            for (int i = 0; i < size; i++) {
                TreeNode curr = queue.poll();
                if (fromLeft) {
                    list.addLast(curr.val);
                } else {
                    list.addFirst(curr.val);
                }
                if (curr.left != null) queue.add(curr.left);
                if (curr.right != null) queue.add(curr.right);
            }
            res.add(list);
            level++;
        }
        return res;
    }
}
```