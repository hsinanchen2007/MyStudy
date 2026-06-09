![image.png](https://pic.leetcode-cn.com/c56f31c68a49ba049f2b740dc481a56e5c347762a9a3cab22228a9975dc23fb0-image.png)

预先判断一步，每次判断是否有左子树，如果有则判断左子树下一个节点是否是叶子节点，如果是计算值，并且结束往下遍历。
```
    class Solution {

        int sum = 0;

        public int sumOfLeftLeaves(TreeNode root) {
            recurseSumOfLeftLeaves(root);
            return sum;
        }

        private void recurseSumOfLeftLeaves(TreeNode root){
            if (root == null) return;
            // 把右子树放上面，这样左子树如果满足条件就结束，不在往下找
            if (root.right != null) recurseSumOfLeftLeaves(root.right);
            if (root.left != null && root.left.left == null && root.left.right == null){
                sum += root.left.val;
                return;
            }
            if (root.left != null) recurseSumOfLeftLeaves(root.left);
        }

    }
```
