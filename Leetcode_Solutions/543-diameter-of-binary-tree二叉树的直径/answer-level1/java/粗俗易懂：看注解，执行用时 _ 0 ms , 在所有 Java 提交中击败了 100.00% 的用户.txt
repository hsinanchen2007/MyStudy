```
class Solution {
    /**
     * 思路：根据题目意思，就是找左右子树的最大深度，最大深度的两个节点之间的距离就是直径，那也就是变成我们要去找左右子树的最大深度问题，
     * 起初我的实现只认为以入参的根节点为基准找左右子树的最大深度然后进行相加就是直径，但是发现可能存在不一定是以根节点为基准得到直径是最大的，
     * 也可能是在子树当中
     * 所以实现过程中用一个全局变量res来记录在获取所有节点的最大深度时先处理看是否以当前节点为根节点得到的直径是否是最大的，是的话就维系一下最大值
     */
    private int res = 0; // 用来记录以某个节点为根节点的时候，最大的路径
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        getMaxDep(root);
        return res;
    }

    private int getMaxDep(TreeNode curRoot){
        if (curRoot == null) return 0;
        //if (curRoot.left == null && curRoot.right == null) return 1;

        int leftDep = getMaxDep(curRoot.left); // 原本这里要+1
        int rightDep = getMaxDep(curRoot.right); // 这里也要+1

        if ((leftDep + rightDep) > res) res = leftDep + rightDep; // 原本这里leftDep + rightDep 还要-2，但是和上面的抵消了，就最后写成这样

        return Math.max(leftDep, rightDep) + 1; // 返回当前根节点的最大深度
    }
}
```
