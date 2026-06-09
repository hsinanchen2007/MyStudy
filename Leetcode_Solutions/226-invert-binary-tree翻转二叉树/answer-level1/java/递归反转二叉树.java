1. 关于复杂度
<br />&nbsp;1.1 时间复杂度为O(n)
<br />&nbsp;1.2 空间负责度为O(1)
2. 我的解题思路
<br />&nbsp;2.1 保存左子树节点
<br />&nbsp;2.2 递归遍历将右子树节点赋给左子树
<br />&nbsp;2.3 递归遍历将左子树节点(2.1保存的)赋给右子树
3. 提交记录
<br />&nbsp;3.1 力扣中耗时0ms,消耗33.4MB内存
<br />&nbsp;3.2 leetcode中耗时0ms,消耗35.8MB内存
4. Q&A
```
/**
 * Problem
 *     226.Invert Binary Tree
 *     https://leetcode.com/problems/invert-binary-tree/
 * Grade of difficulty
 *     Easy
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution {
	/**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 cache left children tree
     *     2.2 recurse to set right tree to left
     *     2.3 recurse to set left tree to right
     * 3.About submit record
     *     3.1 0ms and 33.4MB memory in LeetCode China
     *     3.2 0ms and 35.8MB memory in LeetCode
     * 4.Q&A
     * @param root
     * @return
     */
     public TreeNode invertTree(TreeNode root) {
        if(root==null){
            return root;
        }
        TreeNode node=root.left;
        root.left=invertTree(root.right);
        root.right=invertTree(node);
        return root;
    }
}
```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理<br />
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路