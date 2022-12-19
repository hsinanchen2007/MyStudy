### 解题思路
二叉搜索树 实质相当于 二分法
每次都将nums[0 ... length-1]从中间截断，分成两半。
取中间的nums[mid]为root.val :mid = (l+r+1)/2 
root.letf 根据左半边数据按上述思想生成
root.right 根据右半边数据按上述思想生成
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
    public static TreeNode sortedArrayToBST(int[] nums) {
        return initTree(nums,0,nums.length-1);
    }
	public static TreeNode initTree(int[] nums,int l,int r){
		if(l == r){
			return new TreeNode(nums[l]);
		}else if(l > r){
			return null;
		}
		int mid = (l+r+1)>>1;
		TreeNode t = new TreeNode(nums[mid]);
		t.left = initTree(nums,l,mid-1);
		t.right = initTree(nums,mid+1,r);
		return t;
	}
}
```