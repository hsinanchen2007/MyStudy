思路：
1.数组是有序数列，考虑二叉排序树的特点：将有序数列左边为根结点的左子树，数列右边作为根结点的右子树；
2.数组中值为“本轮”根结点取值；
3.数组为空返回null，意思数组不为空时总会生成结点；
4.递归。

```
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length == 0)
			return null;
		int len = nums.length/2;
		TreeNode ans = new TreeNode(nums[len]);
		ans.left = sortedArrayToBST(Arrays.copyOfRange(nums, 0, len));
		ans.right = sortedArrayToBST(Arrays.copyOfRange(nums, len+1, nums.length));
		return ans;
    }
}
```
