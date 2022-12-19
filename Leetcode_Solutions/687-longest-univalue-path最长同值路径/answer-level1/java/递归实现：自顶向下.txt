### 解题思路
考虑最简单的模型：左子树left，根结点root，右子树right。如果root是第一次分叉的那个结点，那么最大长度等于leftLength+rightLength；如果不是第一次分叉的结点，那就要返回max{leftLength,rightLength},因为最多只能有一次分叉，所以要用一个变量isRoot来判断是不是第一次分叉。

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
   int max = 0;
    public int longestUnivaluePath(TreeNode root) {
        longestPathOfNode(root,true);
        if(root != null) {
        longestUnivaluePath(root.left);
        longestUnivaluePath(root.right);
        }
        return max;
    }

    private int longestPathOfNode(TreeNode root, boolean isRoot){
        if(root == null)
            return 0;
        if(root.left == null && root.right == null)
            return 0;
        int nodeCount = 0;
        int left = 0;
        int right = 0;
        if(root.left != null){
            if(root.val == root.left.val){
                left = longestPathOfNode(root.left, false) + 1;
            }
        }
        if(root.right != null){
            if(root.val == root.right.val){
                right = longestPathOfNode(root.right, false) +1;
            }
        }
        if(isRoot)
            nodeCount = left + right;
        else 
            nodeCount = Math.max(left,right);
        if(nodeCount > max)
            max = nodeCount;
        return nodeCount;
    }

}
```