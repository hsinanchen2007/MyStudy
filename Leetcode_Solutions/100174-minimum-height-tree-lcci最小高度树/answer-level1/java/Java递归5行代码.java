sortedArrayToBST方法是传入一个数组，然后取数组中间的数建立根节点root，然后以中间为分界，将左边的子数组和右边的子数组分别传入sortedArrayToBST进行递归，返回的是左子树和右子树的根节点，令其等于root.left和root.right即可：
```
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length==0) return null;
        TreeNode n = new TreeNode(nums[nums.length/2]);
        n.left = sortedArrayToBST(Arrays.copyOfRange(nums,0,nums.length/2));
        n.right = sortedArrayToBST(Arrays.copyOfRange(nums,nums.length/2+1,nums.length));
        return n;
    }
}
```