[Leetcode-Java(200+题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_337_rob.java)

```java
/**
     * 按题意，不能相连=根节点和左右子树选择只能二选一，每个节点都有选和不选，总共组合个数2^n次，全部循环明显不合适
     * 按经验，树的解题思路就是DFS递归
     * 1.求解左右子树的最大金额（左右子树需要求解2遍，选择了根节点和没有选择根节点的）
     * 2.选择根节点的最大值max1=max(左)+max(右)+跟，没有选择根节点的最大值max2=max(左)+max(右)
     * 3.比较max1和max2，求出最大值
     *
     * @param root
     * @return
     */
    public int rob(TreeNode root) {
        int[] max = doRob(root);
        return Math.max(max[0], max[1]);
    }

    /**
     * 0代表不含根节点，1代表含根节点
     *
     * @param root
     * @return
     */
    private int[] doRob(TreeNode root) {
        int[] res = new int[2];
        if (root == null)
            return res;
        int[] left = doRob(root.left);
        int[] right = doRob(root.right);
        //不包含根节点，最大值为两个子树的最大值之和
        res[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        //包含根节点，最大值为两个子树不包含根节点的最大值加上根节点的值
        res[1] = left[0] + right[0] + root.val;
        return res;
    }
```