1. 关于复杂度
<br />&nbsp;1.1 时间复杂度为O()
<br />&nbsp;1.2 空间负责度为O()
2. 我的解题思路
<br />&nbsp;2.1 这个算法基于深度优先遍历而来
<br />&nbsp;2.2 定义一个整形变量用于存储节点数量
<br />&nbsp;2.3 递归遍历树，每遍历一个节点自增缓存变量
3. 提交记录
<br />&nbsp;3.1 力扣中耗时1ms,消耗40MB内存
<br />&nbsp;3.2 leetcode中耗时0ms,消耗39.1MB内存
4. Q&A

```
/**
 * Problem
 *     222. Count Complete Tree Nodes
 *     https://leetcode.com/problems/count-complete-tree-nodes/
 *     https://leetcode-cn.com/problems/count-complete-tree-nodes/submissions/
 * Grade of difficulty
 *     Medium
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
     *     2.1 this solution is base on depth traversal
     *     2.2 define a integer to cache node number
     *     2.3 recurse to go though tree and increase cache variable
     * 3.About submit record
     *     3.1 1ms and 40MB memory in LeetCode China
     *     3.2 0ms and 39.1MB memory in LeetCode
     * 4.Q&A
     * @param root
     * @return
     */
    public int countNodes(TreeNode root) {
        res=0;
        preOrder(root);
        return res;
    }
    
    private void preOrder(TreeNode root){
        if(root==null){
            return;
        }
        res++;
        preOrder(root.left);
        preOrder(root.right);
    }
}
```
