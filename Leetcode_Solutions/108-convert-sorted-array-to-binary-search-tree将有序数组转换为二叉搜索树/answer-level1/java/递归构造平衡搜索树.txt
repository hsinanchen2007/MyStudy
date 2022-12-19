### 解题思路
此处撰写解题思路
1. 首先选取nums[len/2]作为根节点，于是前半段作为左子树，右装做作为右子树
2. 对于左子树而言，同样先取数组的中间作为根节点，右子树亦然
3. 递归退出条件：当长度为0时，返回空树，当长度为1时，返回自身的一个独立的节点
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
		int len = nums.length;
		if (len == 0) return null;
		if (len == 1) return new TreeNode(nums[0]);
		TreeNode root = new TreeNode(nums[len / 2]);
		int[] numsL = Arrays.copyOf(nums, len/2);
		int[] numsR = Arrays.copyOfRange(nums, len/2 + 1, len);
		root.left = this.sortedArrayToBST(numsL);
		root.right = this.sortedArrayToBST(numsR);
		return root;
    }
}
```