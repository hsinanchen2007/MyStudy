```
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {

        if (nums == null || nums.length == 0) return null;
        return bst(0, nums.length, nums); //注意这里是nums.length,不是nums.length - 1;否则右子树有问题
    }

    private TreeNode bst(int left, int right, int[] nums) {
        
        int middle = left + (right - left) / 2;

        if (left == right) return null;
        
        if (middle == left || middle == right) {
            return new TreeNode(nums[middle]);
        }
        
        TreeNode node = new TreeNode(nums[middle]);
        node.left = bst(left, middle, nums);
        node.right = bst(middle + 1, right, nums);
        return node;
    }
}
```
