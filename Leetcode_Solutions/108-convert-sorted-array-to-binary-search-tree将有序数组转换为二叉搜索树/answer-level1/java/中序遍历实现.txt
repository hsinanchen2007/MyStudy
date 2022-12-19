### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return AVL(nums, 0, nums.length-1);
    }
    public TreeNode AVL(int [] nums,int l,int r) {
		if(l>r)return null;
		//数组中间的值为根结点
		int mid=(l+r)/2;
		TreeNode root= new TreeNode(nums[mid]);
		//左边的数组为左子树，右边的数组为右子树
		root.left=AVL(nums, l, mid-1);
		root.right=AVL(nums, mid+1, r);
		return root;
	}
}
```