题解给的java代码好像有问题,除法的时候要特别注意四舍五入

``` Java
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length == 0) {
            return null;
        }
        return generate(nums, 0, nums.length - 1);

    }

    public TreeNode generate(int[] nums, int start, int end) {
        if (start > end) {
            return null;
        }
        int middle = ((start + end) % 2 == 0) ? (start + end) / 2 : (start + end) / 2 + 1; // 对四舍五入特别判断
        TreeNode tree = new TreeNode(nums[middle]);
        tree.left = generate(nums, start, middle - 1);
        tree.right = generate(nums, middle + 1, end);
        return tree;
    }
}
```