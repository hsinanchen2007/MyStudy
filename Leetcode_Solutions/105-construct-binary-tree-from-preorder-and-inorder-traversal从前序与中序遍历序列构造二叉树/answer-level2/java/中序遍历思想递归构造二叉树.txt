Java 耗时18ms，内存42.2MB
```
/**
 * Problem
 *     105.Construct Binary Tree from Preorder and Inorder Traversal
 *     https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Grade of difficulty
 *     Medium
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution {

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n^2)
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 this solution is base on inOrder
     *     2.2 get root val's from preOrder array,circulate get it from inOrder array(inIndex)
     *     2.3 calculate left tree border(preIndex),reverse to build left and right tree
     * 3.About submit record
     *     3.1 18ms and 42.2MB memory in LeetCode China
     *     3.2 5ms and 36.8MB memory in LeetCode
     * 4.Q&A
     * @param preorder
     * @param inorder
     * @return
     */
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return build(preorder,inorder,0,preorder.length-1,0,inorder.length-1);
    }
    
    private TreeNode build(int[] preOrder, int[] inOrder,int preStart,int preEnd,int inStart,int inEnd){
        if(preStart>preEnd||inStart>inEnd){
            return null;
        }
        int rootVal=preOrder[preStart];
        int inIndex=inStart;
        for(;inIndex<=inEnd;inIndex++){
            if(inOrder[inIndex]==rootVal){
                break;
            }
        }
        int preIndex=inIndex-inStart+preStart;
        TreeNode left=build(preOrder,inOrder,preStart+1,preIndex,inStart,inIndex-1);
        TreeNode root=new TreeNode(rootVal);
        root.left=left;
        root.right=build(preOrder,inOrder,preIndex+1,preEnd,inIndex+1,inEnd);
        return root;
    }
}

```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理<br />
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路
