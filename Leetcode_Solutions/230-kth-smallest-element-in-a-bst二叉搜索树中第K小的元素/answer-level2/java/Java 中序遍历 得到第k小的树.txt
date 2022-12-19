首先应该知道，二叉搜索树（二叉查找树、二叉排序树、BST）的中序遍历就是其所有节点的val按照升序排列。这样根据中序遍历，每找到一个元素判断他是否是第k个元素即可。
```
public class KthSmallest230 {
    private int i = 0;
    private int val = 0;

    public int kthSmallest(TreeNode root, int k) {
        ldr(root, k);
        return val;
    }

    public void ldr(TreeNode root, int k) {
        if (root == null) {
            return;
        }
        ldr(root.left, k);
        if (k == ++i) {
            val = root.val;
        }
        ldr(root.right, k);
    }
}
```
