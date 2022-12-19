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

   private void swap(TreeNode node){
    	TreeNode temp = node.left;
    	node.left=node.right;
    	node.right=temp;
    }

    public TreeNode mirrorTree(TreeNode root) {
        if(root==null)
        	return root;
        Queue<TreeNode> queue= new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty()){
        	TreeNode node = queue.poll();
        	swap(node);
        	if(node.left!=null)
        		queue.offer(node.left);
        	if(node.right!=null)
        		queue.offer(node.right);
        }
        return root;
    }

   
    public TreeNode mirrorTree(TreeNode root){
    	if(root==null)
    		return root;
    	Stack<TreeNode>stack=new Stack<>();
    	TreeNode curNode=root;
    	while(!stack.isEmpty()||curNode!=null){
    		while(curNode!=null){
    			swap(curNode);
    			stack.push(curNode);
    			curNode=curNode.left;
    		}
    		curNode = stack.pop();
    		curNode=curNode.right;
    	}
    	return root;
    }


    public TreeNode mirrorTree(TreeNode root){
    	if(root==null)
    		return root;
    	Stack<TreeNode>stack= new Stack<>();
    	TreeNode curNode=root;
    	while(!stack.isEmpty()||curNode!=null){
    		while(curNode!=null){
    			stack.push(curNode);
    			curNode=curNode.left;
    		}
    		curNode=stack.pop();
    		swap(curNode);
    		curNode=curNode.left;
    	}
    	return root;
    }
}







```