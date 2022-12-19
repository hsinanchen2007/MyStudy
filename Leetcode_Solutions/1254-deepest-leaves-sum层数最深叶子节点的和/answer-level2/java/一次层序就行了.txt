层序遍历二叉树，利用变量size获取每一行的节点数，更新每一行的节点之和。

```
class Solution {
    public int deepestLeavesSum(TreeNode root) {
        int res = 0;
        LinkedList<TreeNode> nodeStack = new LinkedList<>();
        nodeStack.add(root);
        while (!nodeStack.isEmpty()) {
            int size = nodeStack.size();
            int currSum = 0;
            while ((--size) >= 0) {
                TreeNode node = nodeStack.poll();
                currSum += node.val;
                if (node.left != null)
                    nodeStack.add(node.left);
                if (node.right != null)
                    nodeStack.add(node.right);
            }
            res = currSum;
        }
        return res;
    }
}
```
