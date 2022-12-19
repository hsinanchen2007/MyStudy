### 解题思路
flag标志位 识别是否开始连续计算节点

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
	int res=0 ; 

    public int pathSum(TreeNode root, int sum) {
    	if(root==null)return res;
    	helper(root,sum,true);

    	helper(root,sum-root.val,false);
    	return res;
    }
    
    void helper(TreeNode root , int sum,boolean flag) {

    	if(sum==0&&!flag) {
    		res++;

    	}
    	
    	if(root.left!=null) {
    		if(flag)helper(root.left,sum,flag);
        	helper(root.left,sum-root.left.val,false);
    	}
    	
    	if(root.right!=null) {
    		if(flag)helper(root.right,sum,flag);
        	helper(root.right,sum-root.right.val,false);
    	}
    	
    }
}
```