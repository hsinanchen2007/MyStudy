```java
class CBTInserter {
    private TreeNode root;
    /**树的深度*/
    private int depth;
    /**树底层的节点个数*/
    private int bottomSize;

    public CBTInserter(TreeNode root) {
        this.root = root;
        init(root, 0);
    }

    /**初始化*/
    private void init(TreeNode root, int d) {
        if (root == null) {
            return;
        }
        if (d > depth) {
            depth = d;
            bottomSize = 1;
        } else if (d == depth) {
            bottomSize++;
        }
        init(root.left, d + 1);
        init(root.right, d + 1);
    }

    public int insert(int v) {
        return insert(root, v, bottomSize, depth);
    }

    /**递归插入*/
    private int insert(TreeNode root, int v, int bsize, int d) {
        if (d <= 1 && bsize < 2) {
            // 达到倒数第二层或最底层，可直接插入
            if (root.left == null) {
                root.left = new TreeNode(v);
            } else {
                root.right = new TreeNode(v);
            }
            bottomSize++;
            if (bottomSize > (1 << depth)) {
                depth++;
                bottomSize = 1;
            }
            return root.val;
        }
        int size = 1 << d;
        if (bsize < size / 2) {
            // 左子树底层未满，插入左子树
            return insert(root.left, v, bsize, d - 1);
        } else if (bsize < size) {
            // 右子树底层未满，插入右子树
            return insert(root.right, v, bsize - size / 2, d - 1);
        } else {
            // 底层已满，插入左子树底层最左端左节点
            return insert(root.left, v, bsize >> 1, d - 1);
        }
    }

    public TreeNode get_root() {
        return root;
    }

}
```
