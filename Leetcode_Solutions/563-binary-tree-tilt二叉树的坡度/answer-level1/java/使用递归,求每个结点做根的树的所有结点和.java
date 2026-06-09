用递归的方法求每一个结点做根的树的所有结点和,(结点和=左子树结点和+右子树结点和+本结点值),
在求左右子树的结点的时候顺手就可以把坡度算出来,然后对坡度进行累加,最后返回坡度和即可.
```java
class Solution {
    int sum = 0;

    public int findTilt(TreeNode root) {
        getSum(root);
        return sum;
    }

    public int getSum(TreeNode root) {
        if (root != null) {
            int left = getSum(root.left);
            int right = getSum(root.right);
            sum += Math.abs(left - right);
            return root.val + left + right;
        }
        return 0;
    }
}
```