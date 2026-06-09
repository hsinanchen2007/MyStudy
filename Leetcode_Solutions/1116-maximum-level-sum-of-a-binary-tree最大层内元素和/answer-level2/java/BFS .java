```

class Solution {
    public int maxLevelSum(TreeNode root) {
        int res = 1;
        int max = Integer.MIN_VALUE;
        Queue<TreeNode> queue = new LinkedList<>();

        queue.offer(root)
        ;
        int depth = 1;
        while (!queue.isEmpty()) {
            int size = queue.size();
            int temp = 0;
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                temp += node.val;
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
            if (temp > max) {
                max = temp;
                res = depth;
            }
            depth++;
        }
        return res;
    }
}
```
