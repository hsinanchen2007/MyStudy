执行用时 : 1 ms, 在Path Sum的Java提交中击败了96.88% 的用户
内存消耗 : 36.6 MB, 在Path Sum的Java提交中击败了91.42% 的用户
```
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null){
            return false;
        }
        if(root.left==null&&root.right==null&&root.val==sum){
            return true;
        }
        if(root.left==null&&root.right==null&&root.val!=sum){
            return false;
        }
        boolean left = false, right = false;
        int val = sum - root.val;
        if(root.left!=null){
            left = hasPathSum(root.left,val);
        }
        if(root.right!=null){
            right = hasPathSum(root.right,val);
        }
        if(left||right){
            return true;
        }
        return false;
    }
}
```