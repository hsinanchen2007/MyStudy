```java
public class _450 {

    // 二叉树删除一个结点
    public TreeNode deleteNode(TreeNode root, int key) {
        return remove(root, key);
    }

    // 删除以root为根的二分搜索树中的key值，并且返回新的树的根节点
    private TreeNode remove(TreeNode root, int key) {
        if (root == null) {
            return null;
        }
        // 在左边
        if (key < root.val) {
            // remove方法返回的是待删除节点的子树的根节点
            root.left = remove(root.left, key);
            return root;
        } else if (key > root.val) {
            root.right = remove(root.right, key);
            return root;
        } else {
            // 相等，就是要删除的值
            if (root.left == null) {
                // 如果左子树为空，右子树直接接替原来的位置
                TreeNode right = root.right;
                // 待删除节点的右子树指向null
                root.right = null;
                return right;
            } else if (root.right == null) {
                // 如果右子树为空，则把左子树接替原来的位置
                TreeNode left = root.left;
                root.left = null;
                return left;
            } else {
                // 左右子树都不为空的情况
                // 1.找到待删除节点的右子树最小节点
                TreeNode minNode = findMin(root.right);
                // 2.把右子树的最小节点删除，返回一颗新的树
                TreeNode newNode = removeMin(root.right);
                // 3。找出来的最小节点取代root的位置，分别设置其左右指针
                minNode.right = newNode;
                minNode.left = root.left;
                return minNode;
            }
        }
    }

    private TreeNode findMin(TreeNode node) {
        if (node.left == null) {
            return node;
        }
        return findMin(node.left);
    }

    // 删除最小节点，返回新的树的根节点
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
