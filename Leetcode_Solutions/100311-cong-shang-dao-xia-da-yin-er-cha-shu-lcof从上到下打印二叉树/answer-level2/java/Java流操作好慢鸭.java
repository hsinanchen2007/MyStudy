不用 stream 就是 1ms，用了 stream 就变成了 5ms 以上......
```
class Solution {
    private LinkedList<TreeNode> queue = new LinkedList<>();

    public int[] levelOrder(TreeNode root) {
        if (root == null) return new int[0];
        List<Integer> list = new ArrayList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.left != null) queue.offer(node.left);
            if (node.right != null) queue.offer(node.right);
            list.add(node.val);
        }
        int[] res = new int[list.size()];
        for (int i = 0; i < res.length; i++) {
            res[i] = list.get(i);
        }
        return res;
        // return list.stream().mapToInt(Integer::valueOf).toArray();
    }
}
```
