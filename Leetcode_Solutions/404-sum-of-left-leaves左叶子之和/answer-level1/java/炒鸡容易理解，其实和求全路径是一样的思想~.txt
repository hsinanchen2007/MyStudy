```
class Solution {
    int sum = 0;
    private void getSum(TreeNode root, boolean isLeft){
        if(root != null){
            if(isLeft && root.left == null && root.right == null){
                sum += root.val;
            }else{
                getSum(root.left, true);
                getSum(root.right, false);
            }
        }
    }
    public int sumOfLeftLeaves(TreeNode root) {
        getSum(root, false);
        return sum;
    }
}
```
