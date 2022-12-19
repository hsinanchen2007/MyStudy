1. 关于复杂度
<br />&nbsp;1.1 时间复杂度为O(n)
<br />&nbsp;1.2 空间负责度为O(1)
2. 我的解题思路
<br />&nbsp;2.1 定义一个整数用于缓存计算结果
<br />&nbsp;2.2 逆中序遍历(遍历右子树，根节点，左子树)二叉树，将当前节点值与缓存值相加后赋回给当前节点和缓存变量
3. 提交记录
<br />&nbsp;3.1 力扣中耗时1ms,消耗45.1MB内存
<br />&nbsp;3.2 leetcode中耗时1ms,消耗39.7MB内存
4. Q&A

```
/**
 * Problem
 *     538.Convert BST to Greater Tree
 *     https://leetcode.com/problems/convert-bst-to-greater-tree/
 *     https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
 * Grade of difficulty
 *     Easy
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution {
    
    private int sum;
    
	/**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 use a integer to cache plus result
     *     2.2 reverse inOrder to traverse root,plus cache result to current node val and set current node val to cache result
     * 3.About submit record
     *     3.1 1ms and 45.1MB memory in LeetCode China
     *     3.2 1ms and 39.7MB memory in LeetCode
     * 4.Q&A
     * @param root
     * @return
     */
    public TreeNode convertBST(TreeNode root) {
        sum=0;
        inOrder(root);
        return root;
    }
    
    private void inOrder(TreeNode root){
        if(root==null){
            return;
        }
        inOrder(root.right);
        root.val+=sum;
        sum=root.val;
        inOrder(root.left);
    }
}
```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理<br />
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路
