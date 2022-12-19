Java 耗时0ms，内存34.5MB
```
/**
 * Problem
 *     965.Univalued Binary Tree
 *     https://leetcode.com/problems/univalued-binary-tree/
 * Grade of difficulty
 *     Easy
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution {
    
    private int num;
    
    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 this solution is base on preOrder traversal
     *     2.2 use a integer to record root val
     *     2.3 compare current node val in recursion to cache integer
     * 3.About submit record
     *     3.1 0ms and 34.5MB memory in LeetCode China
     *     3.2 0ms and 34.3MB memory in LeetCode
     * 4.Q&A
     * @param root
     * @return
     */
    public boolean isUnivalTree(TreeNode root) {
        if(root==null){
            return true;
        }
        num=root.val;
        return preOrder(root);
    }
    
    private boolean preOrder(TreeNode root){
        if(root==null){
            return true;
        }
        if(num!=root.val){
            return false;
        }
        return preOrder(root.left)&&preOrder(root.right);
    } 
}
```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理<br />
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路