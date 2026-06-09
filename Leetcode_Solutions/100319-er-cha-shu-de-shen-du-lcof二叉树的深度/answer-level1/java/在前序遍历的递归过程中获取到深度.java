### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :43.7 MB, 在所有 Java 提交中击败了100.00%的用户
前序遍历二叉树的递归写法我一般这样写：
```
void preOrder(TreeNode root) {
        if (root != null) {
            System.out.print(root.val + " ");
            preOrder(root.left);
            preOrder(root.right);
        }
    }
```

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

		if(root!=null) {
			int l = maxDepth(root.left);
			int r = maxDepth(root.right);
			return l+1>r+1?l+1:r+1;
		}else {
			return 0;
		}
	}
}
```