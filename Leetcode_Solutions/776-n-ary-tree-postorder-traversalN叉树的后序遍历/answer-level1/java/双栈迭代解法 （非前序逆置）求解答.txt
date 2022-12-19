### 解题思路
使用一个Boolean类型的辅助栈stack2  存储每个结点的子树是否访问过的标记
结点入栈1 标记同结点同时入栈和出栈
当遍历到某节点时若标记为false（默认） 则访问其子树
               若标记为true 说明其子树已经访问完成则输出其值 



### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    List<Integer> resList = new ArrayList<>();
   public List<Integer> postorder(Node root) {
        if(root == null) return resList;
		Stack<Node> stack1 = new Stack<>();
		Stack<Boolean> stack2 = new Stack<>();
		
		stack1.push(root);
		stack2.push(true);
		
		while(!stack1.isEmpty() || root != null) {
			
			if(root != null) {
				
				int length = root.children.size();
				for(int i=length-1;i>=0;i--) {
					stack1.push(root.children.get(i));
					stack2.push(false);
				}	
			}
			
			if(!stack2.peek()) {// the topNode has not been visited;
				root = stack1.peek();
				stack2.pop();	stack2.push(true);
			}else {             // the topNode has been visited;
				resList.add(stack1.pop().val);
				stack2.pop();
                root = null;
			}
			
		}
		
		return resList;
	}
}
```这个算法执行用时高得出奇，几乎是递归解法的10倍
		 有没有大佬帮忙解答下 为什么这么久？