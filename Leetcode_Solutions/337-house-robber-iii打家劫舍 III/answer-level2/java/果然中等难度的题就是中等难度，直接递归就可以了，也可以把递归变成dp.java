
先说动态规划的思想：
这题不能从父亲往儿子dp，因为儿子之间都不认识，这个儿子你打算要了，爹就不能要了，但是别的儿子想要这个爹。
所以从儿子往父亲dp，
父节点的最优解有两种情况：
1.父节点要了，俩儿子都不能选
2.父节点不要，两儿子可以选可以不选
用0表示不选，1表示选。

dp[父]1=dp[儿1]0+dp[儿2]0+父亲的值;
dp[父]0=max((dp[儿1]0+dp[儿2]0,(dp[儿1]0+dp[儿2]1,(dp[儿1]1+dp[儿2]0,(dp[儿1]1+dp[儿2]1))

解释：
父亲要了，就从俩儿子都不选的时候，选最大值
父亲不要了，就从俩儿子选不选，排列组合4中里选。这里实现比较复杂

所以直接用递归
用一个辅助方法，计算不要的时候，将某个节点的不要，转换成儿子节点的随意选择就可以继续递归了。


太真实了，中等难度就不会难


class Solution {
    public int rob(TreeNode root) {
        if (root==null)
            return 0;
        int maxrob0 = rob(root.left)+rob(root.right);
        int maxrob1 = robnot(root.left)+robnot(root.right)+root.val;
        return Math.max(maxrob0,maxrob1);

    }

    public int robnot(TreeNode root){
        if (root==null)
            return 0;
        return rob(root.left)+rob(root.right);
    }
}