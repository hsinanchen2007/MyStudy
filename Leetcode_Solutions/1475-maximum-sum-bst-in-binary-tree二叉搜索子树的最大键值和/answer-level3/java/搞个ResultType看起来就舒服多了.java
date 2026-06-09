### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * 用ResultType，只要子树是二叉搜索树 且
 * 左子树的最大值要小于当前节点 才能把当前节点加入左子树，右子树的最小值要大于当前节点，才能把这个节点加入右子树
 * 所以我们的ResultType要存放当前子树的最大值和最小值，以及当前的和是多少。
 * 每次能加入的时候更新下最大值即可
 */
class Solution {
    int res = 0;

    public int maxSumBST(TreeNode root) {
        helper(root);
        return res;
    }

    private ResultType helper(TreeNode root) {
        if (root == null) {
            return new ResultType(0x3f3f3f3f, 0x80000000, 0, true);
        }
        //divide
        ResultType left = helper(root.left);
        ResultType right = helper(root.right);
        //如果当前节点能和它的左右子树合并为一颗大二叉搜索树,可以更新下全局最大值
        if (left.isBST && right.isBST && left.max < root.val && right.min > root.val) {
            int temp = left.sum + right.sum + root.val;
            res = Math.max(res, temp);
            int min = root.left == null ? root.val : left.min;
            int max = root.right == null ? root.val : right.max;
            return new ResultType(min, max, temp, true);
        }
        //不能合并的情况,那么以这个节点为根节点的子树就不是二叉搜索树
        return new ResultType(root.val, root.val, root.val, false);
    }

    class ResultType{
        int min;
        int max;
        int sum;
        boolean isBST;

        public ResultType(int min, int max, int sum, boolean isBST) {
            this.min = min;
            this.max = max;
            this.sum = sum;
            this.isBST = isBST;
        }
    }
}
```