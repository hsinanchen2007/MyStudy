```
package LEETCODE.树.leetcode二叉树的层次遍历;
import java.util.*;

/**
 * @Author:FuYouJie
 * @Date Create in 2020/1/18 19:39
 */

 class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }
public class Solution {
 	List<List<Integer>>levels=new ArrayList<>();
 	Stack<List<Integer>>stack=new Stack<>();
	public List<List<Integer>> levelOrder(TreeNode root) {
		if(root == null){
			return levels;
		}
		helper(root,0);
		for(int i=stack.size();i>0;i--){
			levels.add(stack.pop());
		}
		return levels;
		

	}
	private void helper(TreeNode node,int  level){
		if(stack.size() == level){
			stack.add(new LinkedList<>());
		}
		stack.get(level).add(node.val);
		if(node.left != null){
			helper(node.left,level+1);
		}
		if (node.right != null){
			helper(node.right,level+1);
		}
	}
}

```
