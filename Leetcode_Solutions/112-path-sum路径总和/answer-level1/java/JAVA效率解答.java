超过99的代码
解析：
第一个if，如果当前节点为空则返回false
第二个if，如果当前节点是叶子节点且满足总和条件，返回true
else，递归遍历左右节点，并用`||`操作连接
```
class Solution {
    public boolean backtrack(int sum,int now,TreeNode h){
        if(h == null) return false;
        if(h.right == null && h.left == null){
            return now + h.val == sum;
        }else{
            return backtrack(sum ,now + h.val,h.left) || backtrack(sum ,now + h.val,h.right);
        }
    }
    public boolean hasPathSum(TreeNode root, int sum) {
        return backtrack(sum,0,root);
    }
}
```