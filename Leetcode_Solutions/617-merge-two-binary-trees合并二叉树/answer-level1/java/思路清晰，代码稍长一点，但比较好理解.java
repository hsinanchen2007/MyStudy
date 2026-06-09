一、总体思路
1. 对比t1和t2两棵树的差异；
2. 将t2合并到t1；
3. 返回t1。

二、详细设计
选择一种树的遍历方式，执行以下步骤
1. 遍历t2，同步遍历t1，对比相同位置的节点差异；
2. t2有而t1没有的节点，则给t1创建一个；
3. t2有而t1也有的节点，将两个值相加，更新t1的节点值。

三、迭代按层遍历

```
/**
 * 广度优先遍历，将树t2合并到树t1.
 * 时间复杂度：O(n)，空间复杂度：最好O(logn)，最坏O(n)。其中，n为t2的节点数。
 * 
 * @param t1
 * @param t2
 * @return
 */
public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
    if (t1 == null) {
        return t2;
    }
    if (t2 == null) {
        return t1;
    }
    
    LinkedList<TreeNode> queue1 = new LinkedList<>();
    LinkedList<TreeNode> queue2 = new LinkedList<>();
    queue1.add(t1);
    queue2.add(t2);

    // 按层遍历t2，同步遍历t1，对比相同位置的节点差异。
    // t2有而t1没有的节点，则给t1创建一个。
    // t2有t1也有的节点，值相加更新t1的节点值。
    while (!queue2.isEmpty()) {
        TreeNode node1 = queue1.poll();
        TreeNode node2 = queue2.poll();
        
        // t2与t1对应节点的值，累计到t1的节点
        node1.val += node2.val;

        if (node2.left != null) {
            // t1左孩子节点不存在，则创建一个，节点值为0（t2有的节点，t1也要有）
            if (node1.left == null) {
                node1.left = new TreeNode(0);
            }
            queue1.add(node1.left);
            queue2.add(node2.left);
        }

        if (node2.right != null) {
            // t1右孩子节点不存在，则创建一个，节点值为0（t2有的节点，t1也要有）
            if (node1.right == null) {
                node1.right = new TreeNode(0);
            }
            queue1.add(node1.right);
            queue2.add(node2.right);
        }
    }

    return t1;
}
```
