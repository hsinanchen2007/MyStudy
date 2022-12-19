### 解题思路
//左子树和右子树的高度差小于1，并且左子树和右子树分别是高度平衡的

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
    public boolean isBalanced(TreeNode root) {
    	if(root==null) {
    		return true;
    	}
        int h= Math.abs(heightOfTree(root.left)-heightOfTree(root.right));
        if(h<=1&&isBalanced(root.left)&&isBalanced(root.right)) {
        	return true;
        }else {
        	return false;
        }
    }
    
    public int heightOfTree(TreeNode root) {
    	if(root==null) {
    		return 0;
    	}
    	return 1+Math.max(heightOfTree(root.left), heightOfTree(root.right));
    }
}
```