### 解题思路
思路就在代码里面，后序遍历，计算当前子节点最大长度

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
    /**
	 * 中序遍历，左主右 前序遍历，主，左 ，右 后序遍历 左，右 ，主
	 * 
	 * 
	 * 正数，那么一定是优势，必须加 负数一定是劣势，但是作为关键节点，可能连接了更大的正数，所以判断。
	 * 
	 * 
	 * 
	 * 那么思路就很清晰了，后序遍历，左，右2个节点的和，以及当前子树最大值，以及最大值的和，代码逻辑很清晰，大家可以看看
	 * 
	 * 
	 * 
	 * @param root
	 * @return
	 */
	public int maxPathSum(TreeNode root) {
		/**
		 * 说了不为null，，，为null，题目就冲突了，但是为了代码稳健性，加个非空判断
		 */
		if (root == null)
			return 0;
		int[] max = new int[1];
		max[0] = Integer.MIN_VALUE;
		
		max[0]=Math.max(doHelper(root, max),max[0]);
		return max[0];

	}

	public int doHelper(TreeNode node, int[] max) {
		int left = 0;
		int val = node.val;
		if (node.left != null) {
			left = doHelper(node.left, max);
			max[0] = Math.max(max[0], left);
			max[0] = Math.max(max[0], left+val);
		}
		int right = 0;
		if (node.right != null) {
			right = doHelper(node.right, max);
			max[0] = Math.max(max[0], right);
			max[0] = Math.max(max[0], left+val+right);
		}
		
		int temp=Math.max(left, right);		
		val = temp > 0 ? val + temp : val;
	
		return val;

	}
}
```