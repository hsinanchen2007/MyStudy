### 使用迭代解法
```java
class Solution {
    public int maxPathSum(TreeNode root) {
        // 1. 判空
        if (root == null) return 0;

        // 2. 使用 DFS 对树 root 进行后序遍历
        Stack<TreeNode> stack = new Stack<>();
        // 保存后序遍历的结果集合
        LinkedList<TreeNode> postOrder = new LinkedList<>();
        stack.push(root);
        while (!stack.isEmpty()) { // DFS
            TreeNode curr = stack.pop();
            // 将遍历的节点放到结果集合的第一个元素位置上
            postOrder.addFirst(curr);
            if (curr.left != null) stack.push(curr.left);
            if (curr.right != null) stack.push(curr.right);
        }

        // 3. 定义保存最终结果的变量
        int result = Integer.MIN_VALUE;

        // 4. 用于缓存每个节点的最大路径和
        Map<TreeNode, Integer> maxRootPath = new HashMap<>(); // cache

        // 5. 计算最大路径和
        for (TreeNode node : postOrder) {
            // 因为 postOrder 集合是后序遍历存储的，所以会先计算叶子节点的最大路径和
            // 注意：每个叶子的最大路径和就是当前叶子节点的值
            int left = Math.max(maxRootPath.getOrDefault(node.left, 0), 0);
            int right = Math.max(maxRootPath.getOrDefault(node.right, 0), 0);
            maxRootPath.put(node, Math.max(left, right) + node.val);
            result = Math.max(left + right + node.val, result);
        }

        return result;
    }
}
```

### 使用递归解法
```java
class Solution {
    private int maxSum = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        maxPathDown(root);
        return maxSum;
    }

    // 递归计算指定节点的最大路径和
    private int maxPathDown(TreeNode node) {
        // 1. 边界条件
        if (node == null) return 0;

        // 2. 分别计算当前节点的左右节点的最大路径和
        int left = Math.max(maxPathDown(node.left), 0);
        int right = Math.max(maxPathDown(node.right), 0);

        // 3. 更新最大路径和结果
        maxSum = Math.max(maxSum, left + right + node.val);

        // 返回当前节点的最大路径和
        return node.val + Math.max(left, right);
    }
}
```