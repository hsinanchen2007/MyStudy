官方探索卡片：二叉搜索树中的方法
> 鉴于我们同时需要插入和搜索操作，为什么不考虑使用一个二叉搜索树结构存储数据呢？

>我们知道，对于二叉搜索树的每个节点来说，它的左子树上所有结点的值均小于它的根结点的值，右子树上所有结点的值均大于它的根结点的值。

>换言之，对于二叉搜索树的每个节点来说，若其左子树共有m个节点，那么该节点是组成二叉搜索树的有序数组中第m + 1个值。

>你可以先独立思考这个问题。请先尝试把多个节点存储到树中。你可能还需要在每个节点中放置一个计数器，以计算以此节点为根的子树中有多少个节点。

https://leetcode-cn.com/explore/learn/card/introduction-to-data-structure-binary-search-tree/66/conclusion/182/

```java
class KthLargest {

    private static class TreeNode {
        public int val;
        public TreeNode left;
        public TreeNode right;
        // 该节点值出现次数
        public int cnt;
        public TreeNode(int x) {
            val = x;
            cnt = 1;
        }
    }

    private TreeNode root;
    private int kth;

    private TreeNode insert(TreeNode root, int n) {
        if (root == null) {
            return new TreeNode(n);
        }
        if (n < root.val) {
            root.left = insert(root.left, n);
        } else if (n > root.val) {
            root.right = insert(root.right, n);
        }
        root.cnt++;
        return root;
    }

    private TreeNode search(TreeNode root, int n) {
        if (root == null) return root;
        // 左子树节点数
        int leftChildCount = root.left == null ? 0 : root.left.cnt;
        // 右子树节点数
        int rightChildCount = root.right == null ? 0 : root.right.cnt;
        // 根节点出现次数
        int rootCount = root.cnt - rightChildCount - leftChildCount;
        // 先在右子树中搜索第n大的节点，如果n小于等于右子树中节点数，说明第n大的节点在右子树
        if (n <= rightChildCount) {
            return search(root.right, n);
        }
        // 如果n大于右子树节点数加根节点出现次数，那么第n大的节点在左子树
        else if (n > rightChildCount + rootCount) {
            return search(root.left, n - rightChildCount - rootCount);
        }
        // 如果n等于右子树节点数加根节点出现次数，那么第n大的节点为根节点
        else {
            return root;
        }

    }

    public KthLargest(int k, int[] nums) {
        kth = k;
        for (int i = 0; i < nums.length; i++) {
            root = insert(root, nums[i]);
        }
    }

    public int add(int val) {
        root = insert(root, val);
        return search(root, kth).val;
    }
}
```