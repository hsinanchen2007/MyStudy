执行用时 :1 ms, 在所有 Java 提交中击败了99.26%的用户
内存消耗 :35.3 MB, 在所有 Java 提交中击败了79.59%的用户
```
class Solution {
    int sum = 0;
    public int sumOfLeftLeaves(TreeNode root) {    
        if(root == null) return sum;
        if(root.left != null && root.left.left == null && root.left.right == null) 
            sum += root.left.val;
        sumOfLeftLeaves(root.left);
        sumOfLeftLeaves(root.right);
        return sum;
    }
}
```
