后序代码段

前序，中序把中间注释的几段代码调换顺序即可

```
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
        
		List<Integer> result = new ArrayList<Integer>();
		Stack<Wrapper> stack = new Stack<>();
		if (root==null) {
			return result;
		}
		
		stack.push(new Wrapper(root));
		
		while(!stack.isEmpty()) {
			
			Wrapper top=stack.pop();
    

            //可读状态或者遍历到叶子节点即可直接读取
			if(top.isReadable || (top.node.right==null&& top.node.left==null)) {
				result.add(top.node.val);
				continue;
			}
			
			//后序遍历 左右根  进栈顺序 根右左
			top.isReadable=true;
			
            //前序,中序调整代码顺序即可
			stack.push(top);
			stack.push(new Wrapper(top.node.right));
			stack.push(new Wrapper(top.node.left));
			
		}
		
		return result;
    }
}

//包装了个一个节点可读的状态属性
class Wrapper{
	TreeNode node;
	boolean isReadable; 
	
	public Wrapper(TreeNode node) {
		this.node=node;
	}
}
```
