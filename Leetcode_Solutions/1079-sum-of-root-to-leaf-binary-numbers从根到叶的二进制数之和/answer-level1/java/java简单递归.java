从根节点开始，每次往下遍历加上当前节点值并乘以2 ， 到叶子节点的时候根节点就相当于在每一层都乘以2 ，满足二进制位置的要求，其他节点也一样
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
    int sum = 0;
    List<List<Integer>> lists = new ArrayList<>();
    public int sumRootToLeaf(TreeNode root) {
        if(root == null) return 0;
       helper(root, 0 );
            return sum;
            
    }
    public void helper(TreeNode root ,int num){
        if(root == null) return;
        num += root.val;
        if(root.left == null && root.right == null)
            sum += num;
        helper(root.left,num * 2);
        helper(root.right, num * 2);
      
    }
}
```
