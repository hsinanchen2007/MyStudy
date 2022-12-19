根据前缀和求路径和的一般方法，先序遍历+前缀参数
```
class Solution129 {
    public int sum = 0;
    public int sumNumbers(TreeNode root) {
        preOrder(root, 0);
        return sum;
    }

    private void preOrder(TreeNode root, int prefix){
        if(root == null) return;
        if(root.left == null && root.right == null)
            sum += prefix * 10 + root.val;
        else{
            preOrder(root.left, prefix * 10 + root.val);
            preOrder(root.right, prefix * 10 + root.val);
        }
    }
}
```
