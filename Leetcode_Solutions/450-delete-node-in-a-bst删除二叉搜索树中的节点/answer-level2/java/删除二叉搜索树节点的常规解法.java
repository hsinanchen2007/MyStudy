![通过.png](https://pic.leetcode-cn.com/115919f90119d86d41737438866dfd29594c05109c32558e21cf013d24cfef95-%E9%80%9A%E8%BF%87.png)

**思路：**
如果要删除的节点比根 root 的值小，则从左子树中删除 key 节点；
如果要删除的节点比根 root 的值大，则从右子树中删除 key 节点；
当 key 和 root 的值相等的时候，则需要删除该节点，这其中又有三种不同的情况：
- 当该节点 (root 节点) 的左子树为空时，断开该节点与右子树的连接 (**注意保存右子树**)，返回该节点的右子树
- 当该节点的右子树为空时，断开连接，返回该节点的左子树
- 该节点左右子树都不为空时，**将该节点右子树中的最小节点替代该元素**

我这里使用两个辅助方法，minimun 方法用于返回一棵树的最小节点；removeMin 方法用于删除一棵树的最小节点

代码如下所示：
```java
class Solution {

    public TreeNode deleteNode(TreeNode root, int key) {

        if (root == null)
            return null;

        if (key < root.val) {
            // key 比根小，则从左子树中删除 key 节点
            root.left = deleteNode(root.left, key);
            return root;
        } else if (key > root.val) {
            // key 比根大，则从右子树中删除 key 节点
            root.right = deleteNode(root.right, key);
            return root;
        } else { // key == root.val
            // 相等删除该节点
            if (root.left == null) {
                // 如果该节点的左子树为空，返回该节点的右子树
                TreeNode right = root.right;
                root.right = null;
                return right;
            }

            if (root.right == null) {
                // 如果该节点的右子树为空，返回该节点的左子树
                TreeNode left = root.left;
                root.left = null;
                return left;
            }

            // 如果该节点的左右子树都不为空，则将该节点右子树中的最小元素替代该元素
            TreeNode rMin = minimun(root.right);
            rMin.right = removeMin(root.right);
            rMin.left = root.left;

            root.left = root.right = null;
            return rMin;
        }
    }

    // 返回以 node 为根的最小节点 (传参的时候保证了 node 不为空，这里不进行非空判断)
    private TreeNode minimun(TreeNode node) {
        if (node.left == null)
            return node;
        return minimun(node.left);
    }

    // 删除以 node 为根的最小节点 (传参的时候保证了 node 不为空，这里不进行非空判断)
    private TreeNode removeMin(TreeNode node) {
        if (node.left == null) {
            TreeNode right = node.right;
            node.right = null;
            return right;
        }
        node.left = removeMin(node.left);
        return node;
    }
}

```
