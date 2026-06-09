### 解题思路
执行用时 :
0 ms
, 在所有 java 提交中击败了
100.00%
的用户
内存消耗 :
34.5 MB
, 在所有 java 提交中击败了
39.07%
的用户

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
    Queue<TreeNode> guangduQueue=new LinkedList<TreeNode>();
    public TreeNode invertTree(TreeNode root) {
        if(root==null) {
    		return null;
    	}
    	if(root.left==null&&root.right==null) {
    		return root;
    	}
    	TreeNode t=root;
    	guangduQueue.offer(root);
    	while(!guangduQueue.isEmpty()) {
    		 root=guangduQueue.poll();
    		 if(root.left==null&&root.right==null) {
    			 //nothing
    		 }
    		 else if(root.left==null&&root.right!=null) {
    			 root.left=new TreeNode(-1);
    			 root.left=root.right;
    			 root.right=null;
    		 }
             else if(root.left!=null&&root.right==null) {
            	 root.right=new TreeNode(-1);
    			 root.right=root.left;
    			 root.left=null;
    		 }
             else {
            	 TreeNode temp=root.left;
        		 root.left=root.right;
        		 root.right=temp;
             }
    		 if(root.left!=null)
    		 guangduQueue.offer(root.left);
    		 if(root.right!=null)
    		 guangduQueue.offer(root.right);
    		 
    		
    	}
    	return t;
      
        
    }
}
```