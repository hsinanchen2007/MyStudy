```
class Solution {
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> maxList = new ArrayList<>();
        if (root == null) {
            return maxList;
        }
        List<TreeNode> queue = new ArrayList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int max = queue.get(0).val;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.remove(0);
                if (node.val > max) {
                    max = node.val;
                }
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            maxList.add(max);
        }
        return maxList;
    }
}
```
