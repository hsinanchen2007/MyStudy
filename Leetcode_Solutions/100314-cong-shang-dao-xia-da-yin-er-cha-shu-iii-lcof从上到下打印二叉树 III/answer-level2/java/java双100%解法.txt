### 解题思路
使用标志位flag,将其初始化为true；每循环一次，flag变化一次。当flag为false时，元素在头部加入列表，为true时元素在尾部加入列表
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
		boolean flag=true;
		List<List<Integer>> res = new ArrayList<List<Integer>>();
		if(root != null) queue.add(root);
		while(!queue.isEmpty())
		{
			List<Integer> ans = new ArrayList<Integer>();
			flag=!flag;
			for(int i = queue.size(); i>0; i--) {
			TreeNode a=queue.poll();
			if(flag)
			{
				ans.add(0,a.val);
			}
			else
			{
			ans.add(a.val);
			}
			if(a.left!=null)
			{
				queue.add(a.left);
			}
			if(a.right!=null)
			{
				queue.add(a.right);
			}
			}
			//if(res.size() % 2 == 1) Collections.reverse(ans);
			res.add(ans);
		}
		return res;
		}
    }

```