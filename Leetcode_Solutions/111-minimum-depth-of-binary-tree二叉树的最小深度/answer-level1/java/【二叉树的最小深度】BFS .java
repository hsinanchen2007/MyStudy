二叉树层次有关的题，比如[二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)，[二叉树的层次遍历Ⅱ](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)，又或者这道最小深度，都是直接BFS去遍历树，用两个变量记录当前层节点数和下一层节点数。
```java
class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int currLayerCount = 0; // 记录当前层的节点数
        int nextLayerCount = 0; // 记录下一层的节点数
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        currLayerCount++;
        int minDepth = 1;
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            currLayerCount--;
            // 找到的叶子节点，直接退出
            if (node.left == null && node.right == null) {
                break;
            }
            if (node.left != null) {
                queue.offer(node.left);
                nextLayerCount++;
            }
            if (node.right != null ) {
                queue.offer(node.right);
                nextLayerCount++;
            }
            // 当前层的节点遍历完了，说明要进入下一层了，深度加1
            if (currLayerCount == 0) {
                minDepth++;
                // 更新当前层节点数和下一层节点数
                currLayerCount = nextLayerCount;
                nextLayerCount = 0;
            }
        }
        return minDepth;
    }
}
```
![image.png](https://pic.leetcode-cn.com/b14cc6fc3a0a85cac1d2780336755773304e4abccd437d91596cdc551228a383-image.png)
