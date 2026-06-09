### 解题思路
这道题的切入点就在于可以通过栈来实现迭代，先将通过while循环找到整棵树后序遍历的第一个结点（注意：每一次往栈中压入一个节点，都需要让其与他的子节点切断连接，这样子在出栈才能保证不会重复遍历）。
然后将栈中的节点一个一个弹出，再判断是否还有右子节点。


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
   	 public List<Integer> postorderTraversal(TreeNode root) {
	        List<Integer>  list=new ArrayList();
	        Stack<TreeNode> s=new Stack();
            if(root==null)
                return list;
            s.push(root); 		//先将头节点压入
	        while(root.right!=null || root.left!=null){
	            if(root.left!=null){
	                s.push(root.left);
	                root.left=null;
	                root=s.peek();
	            }else if(root.right!=null){
	                s.push(root.right);
	                root.right=null;
	                root=s.peek();
	            }
	        }
	        while(!s.isEmpty()){
	            TreeNode node=s.peek();
	            if(node.left==null && node.right== null){
	                list.add(s.pop().val);
	                continue;
	            }
	            if(node.left!=null){
	                s.push(node.left);
	                node.left=null;
	                continue;
	            }
	            if(node.right!=null){
	                s.push(node.right);
	                node.right=null;
	                continue;
	            }	            
	        }
	        return list;
	    }
}
```