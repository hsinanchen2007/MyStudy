```
class Solution {
    //寻找l到r区域中的最大值索引
	public int max(int[] nums,int l,int r){
		int max_i = l;
		for(int i=l;i<r;i++){
			if(nums[max_i] < nums[i]){
				max_i = i;
			}
		}
		return max_i;
	}
    public TreeNode construct(int nums[] ,int l,int r){
		if(l == r) return null;
		int max_i = max(nums,l,r);
		TreeNode root = new TreeNode(nums[max_i]);
		root.left = construct(nums, l, max_i);
		root.right = construct(nums, max_i+1, r);
		return root;
	}
    public TreeNode constructMaximumBinaryTree1(int[] nums) {
		return construct(nums, 0, nums.length);
	}
}
```
