### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :38.7 MB, 在所有 Java 提交中击败了27.70%的用户

迭代记录层数，返回最大层数。

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
    public int maxDepth(TreeNode root) {
		int[] max = {0};
		backtrack(root, 0, max);

		return max[0];
	}

	private static void backtrack(TreeNode root, int lev, int[] max){
		if(root==null){
            if(lev>max[0]){max[0] = lev;}
            return;
        }

		backtrack(root.left, lev+1, max);

		backtrack(root.right, lev+1, max);

		return;		
	}
}
```