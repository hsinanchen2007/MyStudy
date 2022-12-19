```Java
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        // 1. 构造一个fakeRoot节点作为根节点的父节点
        TreeNode fakeRoot = new TreeNode(Integer.MAX_VALUE);
        fakeRoot.left = root;
        // 2. 定位要删除的节点，需要找到其父节点
        TreeNode[] result = new TreeNode[2];    // 0存储父节点，1存储目标节点
        if (!findNode(fakeRoot, root, result, key)) return root; // 没找到则返回原来的根节点
        TreeNode parent = result[0];
        TreeNode target = result[1];
        // 3. 做删除操作
        doDelete(parent, target);
        // 4. 返回删除后的根节点
        return fakeRoot.left;
    }

    // 查找目标节点，需要保存父节点的引用
    // 返回boolean值可以提前结束查找
    private boolean findNode(TreeNode parent, TreeNode root, TreeNode[] result, int key) {
        if (root == null) return false;
        if (root.val == key) {
            result[0] = parent;
            result[1] = root;
            return true;
        }
        return findNode(root, root.left, result, key)
                || findNode(root, root.right, result, key);
    }

    // 做删除节点操作
    private void doDelete(TreeNode parent, TreeNode target) {
        // 1. 如果target节点的右子树为空，则直接将左子树补上
        if (target.right == null) {
            if (parent.left == target) {
                parent.left = target.left;
            } else {
                parent.right = target.left;
            }
            return;
        }
        // 2. 右子树不为空时
        //  2.1 在右子树中找最小的那个节点
        TreeNode[] minNodeAndParent = findMinNode(target, target.right);
        //  2.2 将最小节点的值填充到target节点，即删除当前节点
        target.val = minNodeAndParent[1].val;
        //  2.3 递归删除最小节点
        doDelete(minNodeAndParent[0], minNodeAndParent[1]);
    }

    // 找一棵树中的最小节点
    // 一棵搜索树的最小节点是最左的那个节点
    private TreeNode[] findMinNode(TreeNode parent, TreeNode root) {
        if (root.left == null) {
            TreeNode[] ans = new TreeNode[2];
            ans[0] = parent;
            ans[1] = root;
            return ans;
        }
        return findMinNode(root, root.left);
    }
}
```
