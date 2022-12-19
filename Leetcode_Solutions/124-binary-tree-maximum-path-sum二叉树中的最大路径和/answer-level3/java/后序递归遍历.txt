1. 关于复杂度
<br />&nbsp;1.1 时间复杂度为O(n)
<br />&nbsp;1.2 空间负责度为O(1)
2. 我的解题思路
<br />&nbsp;2.1 因为需要计算任意节点到任意节点的最大路径和，所以下面是我的一点思路
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.1.1 分别计算左右子树的最大路径和，并将他们与0进行比较(如果是负数就不要)
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.1.2 设置一个变量去存储计算过程中最大的结果，并在遍历过程中用他与左右子树与当前节点值相加结果对比
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.1.3 对比左右子树最大路径和并返回他们之间的最大值与当前节点的值
3. 提交记录
<br />&nbsp;3.1 力扣中耗时3ms,消耗43.1MB内存
<br />&nbsp;3.2 leetcode中耗时1ms,消耗40.5MB内存
4. Q&A

```
/**
 * Problem
 *     124.Binary Tree Maximum Path Sum
 *     https://leetcode.com/problems/binary-tree-maximum-path-sum/
 *     https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
 * Grade of difficulty
 *     Hard
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution {
    
    private int res;
    
	/**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 cause we need to calculate max path sum,so here is my thought
     *         2.1.1 cal left children tree and right children tree path sum,compare their to 0
     *         2.1.2 set a temp integer to cache max result,and use it to compare to left res plus right res and current val
     *         2.1.3 compare left res to right val,and return the result which is compare result plus current node val
     * 3.About submit record
     *     3.1 3ms and 43.1MB memory in LeetCode China
     *     3.2 1ms and 40.5MB memory in LeetCode
     * 4.Q&A
     * @param root
     * @return
     */
    public int maxPathSum(TreeNode root) {
        res=Integer.MIN_VALUE;
        traverse(root);
        return res;
    }
    
    private int traverse(TreeNode root){
        if(root==null){
            return 0;
        }
        int left=Math.max(traverse(root.left),0);
        int right=Math.max(traverse(root.right),0);
        int temp=root.val+left+right;
        res=Math.max(res,temp);
        return Math.max(left,right)+root.val;
    }
    
}
```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理<br />
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路

