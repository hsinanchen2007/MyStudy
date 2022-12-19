```java
class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        if (root == null) {
            return Collections.emptyList();            
        }
        List<Double> averages = new LinkedList<>();
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);
        int size, n;
        TreeNode node;
        while (!queue.isEmpty()) {
            size = n = queue.size();
            double sum = 0;
            while (n-- > 0) {
                node = queue.remove();
                sum += node.val;
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
            averages.add(sum / size);
        }
        return averages;
    }

}
```
