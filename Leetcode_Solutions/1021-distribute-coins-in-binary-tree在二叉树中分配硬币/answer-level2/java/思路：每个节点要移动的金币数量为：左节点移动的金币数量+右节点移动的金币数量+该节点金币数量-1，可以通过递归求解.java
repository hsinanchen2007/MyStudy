执行用时 :1 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :35.8 MB, 在所有 java 提交中击败了78.79%的用户
```
class Solution {
    int count = 0;
    public int distributeCoins(TreeNode root) {
        if(root == null)
            return 0;
        getResult(root);
        return count;
       
    }
    public int getResult(TreeNode root){
        if(root == null)
            return 0;
        int leftCount = getResult(root.left);
        int rightCount = getResult(root.right);
        count += (Math.abs(leftCount)+Math.abs(rightCount));
        return leftCount+rightCount+root.val-1;
    }
}
```
