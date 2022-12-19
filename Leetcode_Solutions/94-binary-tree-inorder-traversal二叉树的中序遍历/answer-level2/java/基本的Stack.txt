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
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
    	//新建一个栈来处理递归
    	Stack<TreeNode> st=new Stack<>();
    	//新建一个List来保存遍历的顺序
    	List<Integer> list = new ArrayList<>();
    	TreeNode curr = root;
    	//当根节点不为空或者栈不为空的时候，进行操作
    	while(curr != null || !st.isEmpty())
    	{
    		//当当前结点不为空的时候
    		while(curr != null)
    		{
    			//进栈
    			st.push(curr);
    			//当前结点变为做结点
    			curr=curr.left;
    		}
    		//当当前结点为空的时候，将栈顶的结点pop，并且保存到list中，将当前结点转化为右节点
    		curr=st.pop();
    		list.add(curr.val);
    		curr=curr.right;
    	}
        return list;

    }
}
```