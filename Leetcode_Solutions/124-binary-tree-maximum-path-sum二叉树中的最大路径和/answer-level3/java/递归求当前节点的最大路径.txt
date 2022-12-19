执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
99.40%
的用户
内存消耗 :
44 MB
, 在所有 Java 提交中击败了
34.88%
的用户
```
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
    int max=Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        cal(root);
        return max;
    }
    private int cal(TreeNode node){
        if(node==null)return 0;
        if(node.val>max)max=node.val;
        int left = node.val+cal(node.left);
        int right = node.val+cal(node.right);
        if(left+right-node.val>max)max=left+right-node.val;
        if(left>max)max=left;
        if(right>max)max=right;
        return Math.max(node.val,Math.max(left,right));
    }
    
}
```
