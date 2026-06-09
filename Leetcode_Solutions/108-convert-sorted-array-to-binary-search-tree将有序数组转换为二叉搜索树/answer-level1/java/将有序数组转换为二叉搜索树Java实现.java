采用递归的方法来构造二叉搜索树：

二叉搜索树的定义：
每个节点的值都比左子树中最大值要大， 比右子树最小值要小。
由于给定的数组为有序数组，我们可以很好地利用这个性质找到根节点，以及左子树数组和右子树数组。

算法：
- 根节点：mid = (l+r+1) >> 1     new TreeNode(nums[mid])
- 左子树数组：[l, mid-1]
- 右子树数组：[mid+1, r]
- 终止条件： l > r

```
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        //采用递归的方法构建
        int len = nums.length;
        TreeNode root = helper(0, len-1, nums);
        return root;
    }

    public TreeNode helper(int l, int r, int[] nums) {
        if(l>r) return null;
        int mid = (l+r+1) >> 1; //这里记得+1来取右
        TreeNode root = new TreeNode(nums[mid]);
        root.left = helper(l, mid-1, nums);
        root.right = helper(mid+1, r, nums);
        return root;
    }
}
```
