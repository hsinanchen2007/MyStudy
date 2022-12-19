广度优先遍历存储每个结点，然后反向遍历结点，将各结点的值加到其父节点，此步操作以后所有结点的值都成为该结点作为根节点的子树的结点值的和。
然后再遍历每个非根结点的结点。对于每个结点，如果将该结点连向其父结点的边切断，则该结点的值为一个子树的结点值的和，再用根结点的值减去该结点的值即为另一个子树的结点值的和，计算两个和的乘积，如果当前乘积比最大乘积大，则更新最大乘积。
```
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
    public int maxProduct(TreeNode root) {
        final int MODULO = 1000000007;
        List<TreeNode> nodesList = new ArrayList<TreeNode>();
        Map<TreeNode, TreeNode> childParentMap = new HashMap<TreeNode, TreeNode>();
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            nodesList.add(node);
            TreeNode left = node.left, right = node.right;
            if (left != null) {
                childParentMap.put(left, node);
                queue.offer(left);
            }
            if (right != null) {
                childParentMap.put(right, node);
                queue.offer(right);
            }
        }
        for (int i = nodesList.size() - 1; i > 0; i--) {
            TreeNode node = nodesList.get(i);
            TreeNode parent = childParentMap.get(node);
            if (parent != null)
                parent.val += node.val;
        }
        long maxProduct = 0;
        for (int i = nodesList.size() - 1; i > 0; i--) {
            TreeNode node = nodesList.get(i);
            int value1 = node.val, value2 = root.val - node.val;
            long product = (long) value1 * (long) value2;
            maxProduct = Math.max(maxProduct, product);
        }
        int maxProductModulo = (int) (maxProduct % MODULO);
        return maxProductModulo;
    }
}
```
