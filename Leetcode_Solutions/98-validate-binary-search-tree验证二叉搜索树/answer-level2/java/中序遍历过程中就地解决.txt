### 解题思路
众所周知，二叉搜索树中序遍历可以得到一个升序的集合，那么中序遍历过程，前一个数值(prev)要小于后一个数值(cur)，那只要判定prev >= cur这个搜索树就作废False,反之，整个遍历流程跑通的话就返回True

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
    public boolean isValidBST(TreeNode root) {
        if(root == null) {
        	return true;
        }
        Stack<TreeNode> stack = new Stack<TreeNode>();
        //迭代中序遍历
        TreeNode cur = root;
        int preVal = -1;
        boolean first = true; 
        int curVal = -1;
        while(cur != null || !stack.isEmpty()) {
        	preVal = curVal;
        	while(cur != null) {
        		stack.push(cur);
        		cur = cur.left;
        	}
        	cur = stack.pop();
        	curVal = cur.val;
        	if(first) {//第一次没必要比较
        		first = false;
        	} else {
        		if(preVal >= curVal) {
        			return false;
        		}
        	}
        	cur = cur.right;
        }
		return true;
    }
}
```