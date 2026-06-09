使用广度优先搜索。使用`Map`记录每个子节点对应的父节点。遍历`Map`，如果一个子节点是叶节点且该子节点的值等于`target`，则判断该子节点是其父节点的左子节点还是右子节点，并将其父节点的对应子节点设为`null`，然后将该子节点从`Map`中删除。重复上述步骤直到没有子节点被删除。最后判断根节点是否为叶子节点且值等于`target`，如果根节点符合该条件则返回`null`，否则返回根节点。

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
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        Map<TreeNode, TreeNode> childParentMap = new HashMap<TreeNode, TreeNode>();
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
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
        boolean flag = true;
        while (flag) {
            flag = false;
            Set<TreeNode> keySet = childParentMap.keySet();
            Set<TreeNode> removeSet = new HashSet<TreeNode>();
            for (TreeNode node : keySet) {
                if (isLeaf(node) && node.val == target) {
                    TreeNode parent = childParentMap.get(node);
                    if (parent == null)
                        return null;
                    else {
                        if (node == parent.left)
                            parent.left = null;
                        else if (node == parent.right)
                            parent.right = null;
                        removeSet.add(node);
                        flag = true;
                    }
                }
            }
            for (TreeNode node : removeSet)
                childParentMap.remove(node);
        }
        if (isLeaf(root) && root.val == target)
            root = null;
        return root;
    }

    public boolean isLeaf(TreeNode node) {
        return node != null && node.left == null && node.right == null;
    }
}
```
