基本思路是每次循环先找到最左边的叶子结点，中间把经过的结点入栈保存，然后输出叶子结点，栈中pop出中间结点输出，转到中间结点的右孩子，继续循环；
需要注意的问题是：循环结束条件是栈非空或者右孩子非空，这里要注意右孩子非空时，如果右孩子没有子孩子（为单一叶子结点），要break出来，否则输出完该节点后还要pop，此时栈为空，会发生异常

```
    Stack<TreeNode> st=new Stack<TreeNode>();
    List<Integer> result=new ArrayList<Integer>();
    TreeNode temp=root;
    	while(!st.empty()||temp!=null)
    	{
    		if(temp!=null)
    		{
    			while(temp.left!=null)
    			{
    				st.push(temp);
    				temp=temp.left;
    			}
    			//st.push(temp);
    			result.add(temp.val);
    			if(temp.right!=null)
    			{
    				temp=temp.right;
    				continue;
    			}
    			else if(temp.left==null&&temp.right==null&&st.empty())
    				break;
    		}
    		TreeNode median=st.pop();
    		result.add(median.val);
    		temp=median.right;	
    	}
	return result;

```
