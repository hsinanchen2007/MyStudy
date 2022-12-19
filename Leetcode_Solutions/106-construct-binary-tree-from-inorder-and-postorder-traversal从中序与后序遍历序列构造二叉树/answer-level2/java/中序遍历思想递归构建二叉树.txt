Java 耗时32ms，内存37.6MB
(PS:我个人觉得这个解法并没有达到我心理要求，还存在很大的优化空间，之后有时间我会再优化)
```
/**
 * Problem
 *     106.Construct Binary Tree from Inorder and Postorder Traversal
 *     https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * Grade of difficulty
 *     Medium
 * Related topics
 *     105.Construct Binary Tree from Preorder and Inorder Traversal
 * @author cartoon
 * @version 1.0
 */
class Solution {

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n^2)
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 this solution is base on inOrder and solution 105
     *     2.2 get root val's from postOrder array,circulate get it from inOrder array(inIndex)
     *     2.3 calculate left tree border(postIndex),reverse to build left and right tree
     * 3.About submit record
     *     3.1 32ms and 37.6MB memory in LeetCode China
     *     3.2 4ms and 36.1MB memory in LeetCode
     * 4.Q&A
     * @param inorder
     * @param postorder
     * @return
     */
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return build(inorder,postorder,0,inorder.length-1,0,postorder.length-1);
    }
    
    private TreeNode build(int[] inOrder,int[] postOrder,int inStart,int inEnd,int postStart,int postEnd){
        if(inStart>inEnd||postStart>postEnd){
            return null;
        }
        int rootVal=postOrder[postEnd];
        int inIndex=inStart;
        for(;inIndex<=inEnd;inIndex++){
            if(inOrder[inIndex]==rootVal){
                break;
            }
        }
        int postIndex=inIndex-inStart+postStart;
        TreeNode left=build(inOrder,postOrder,inStart,inIndex-1,postStart,postIndex-1);
        TreeNode root=new TreeNode(rootVal);
        root.left=left;
        root.right=build(inOrder,postOrder,inIndex+1,inEnd,postIndex,postEnd-1);
        return root;
    }
}
```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理<br />
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路*斜体*