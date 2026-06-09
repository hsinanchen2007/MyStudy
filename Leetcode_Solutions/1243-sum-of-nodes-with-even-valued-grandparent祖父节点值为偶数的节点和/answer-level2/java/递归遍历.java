题解：
递归遍历
首先判断节点是否为偶数。如果为偶数，则查找孙子节点，并将孙子节点求和；如果为奇数，则查找下一个节点；

    //返回值
    private int result = 0;

    public int sumEvenGrandparent(TreeNode root) {
        bps(root, 0);
        return result;
    }

    private void bps(TreeNode root, int level) {
        if(root == null) {
            return;
        }

        if((root.val % 2 == 0)) {//判断节点是否为偶数
            depth(root.left, level+1, level);
            depth(root.right, level+1, level);
        }

        bps(root.left, level + 1);
        bps(root.right, level + 1);
    }

    private void depth(TreeNode root, int curLevel, int oriLevel) {
        if(root == null) return;

        if(curLevel - oriLevel == 2) { //查找孙子节点
            result += root.val;
            return;
        }

        depth(root.left, curLevel + 1, oriLevel);
        depth(root.right, curLevel + 1, oriLevel);
    }