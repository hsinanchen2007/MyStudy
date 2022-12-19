代码都有注释，思路是保存所有路径的的最大值，当值小于0则重置为0.
[leetcode 题解合集 有意思的题目 欢迎start](https://github.com/ifgyong/leetCode/wiki/%5Bleetcode--0124%5D%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E7%9A%84%E6%9C%80%E5%A4%A7%E8%B7%AF%E5%BE%84%E5%92%8C)

```
 int maxRootSum = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        getMaxRootSum(root);
        return maxRootSum;
    }
    private int getMaxRootSum(TreeNode root){
        if (root == null)return 0;
        int left = Math.max(getMaxRootSum(root.left),0);//节点的和小于0 则舍弃 重置为0
        int right = Math.max(getMaxRootSum(root.right),0);////节点的和小于0 则舍弃 重置为0
        maxRootSum = Math.max(maxRootSum,root.val+left+right);//每次和最大值进行对比，保存最大值
        return root.val + Math.max(left,right);////当前节点的最大值等于左边和右边的最大值加上当前节点
    }
```
