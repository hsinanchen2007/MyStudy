执行用时 :1 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :37.7 MB, 在所有 java 提交中击败了100.00%的用户
```
class Solution {
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        TreeNode left, right;

        if(root == null)
            return null;
        //如果是叶子节点，判断是否需要删去
        if(root.left == null && root.right == null){
            if(root.val < limit)
                return null;
            return root;
        }
        left = sufficientSubset(root.left, limit - root.val);
        right = sufficientSubset(root.right, limit - root.val);
        //如果两个子树都被删掉,说明这个节点是不足节点
        if(left == null && right == null)
            return null;
        //没被全删点就说明不是不足节点，保留即可
        root.left = left;
        root.right = right;
        return root;
    }
}
```
