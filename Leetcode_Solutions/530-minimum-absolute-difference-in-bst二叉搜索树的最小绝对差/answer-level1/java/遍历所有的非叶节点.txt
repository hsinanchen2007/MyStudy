对于每一个非叶节点来说,与他的左子树的最右边的节点(也就是左子树的最大值)比较,再与他的右子树的最左边的节点(也就是右子树的最小值)比较.取两个差的最小值,然后返回所有非叶节点最小值中的最小值
```Java
class Solution {
    private int min = 1000000;

    public int getMinimumDifference(TreeNode root) {
        eachNode(root);
        return min;
    }

    public void eachNode(TreeNode root) {
        if (root != null) {
            if (root.left != null) {
                TreeNode left = root.left;
                while (left.right != null)
                    left = left.right;
                int value = root.val -left. val;
                if (value < min)
                    min = value;
            }
            if (root.right != null) {
                TreeNode right = root.right;
                while (right.left != null)
                    right = right.left;
                int value = right.val - root.val;
                if (value < min)
                    min = value;
            }
            eachNode(root.left);
            eachNode(root.right);
        }
    }
}
```