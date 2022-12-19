最正确,直观,简单,高效的解法!!


```reasonml
 //记录递归中最大的值,如果均为负数,则默认返回1
    int res = 0;
    public int maxSumBST(TreeNode root) {
        if (root == null) return res;
        recursion(root);
        return res;
    }

    //采用数组记录递归结果
    //[isTree,min,max,sum]
    //[是否BST,该树最小值,该树最大值,该树节点之和]
    private int[] recursion(TreeNode root) {
        int isBST = -1;
        int min = 0;
        int max = 0;
        int sum = 0;

        //叶子节点必是BST
        if (root.left == null && root.right == null) {
            isBST = 1;
            min = root.val;
            max = root.val;
            sum = root.val;
            //左右子树都在时,需满足: 左右子树均为BST && 大于左子树的最大值, 小于右子树的最小值
        } else if (root.left != null && root.right != null) {
            int[] l = recursion(root.left);
            int[] r = recursion(root.right);
            if (r[0] == 1 && l[0] == 1 && root.val > l[2] && root.val < r[1]) {
                isBST = 1;
                min = l[1];
                max = r[2];
                sum = root.val + r[3] + l[3];
            }
            //左子树在时,需满足: 左子树为BST && 大于左子树的最大值
        } else if (root.left != null) {
            int[] l = recursion(root.left);
            if (l[0] == 1 && l[2] < root.val) {
                isBST = 1;
                min = l[1];
                max = root.val;
                sum = root.val + l[3];
            }
            //右子树在时,需满足: 右子树为BST && 小于右子树的最小值
        } else if (root.right != null) {
            int[] r = recursion(root.right);
            if (r[0] == 1 && r[1] > root.val) {
                isBST = 1;
                min = root.val;
                max = r[3];
                sum = root.val + r[3];
            }
        }
        //如果该树isBST,就记录
        if (isBST == 1) {
            res = Math.max(res, sum);
        }
        return new int[]{isBST, min, max, sum};
    }
```
