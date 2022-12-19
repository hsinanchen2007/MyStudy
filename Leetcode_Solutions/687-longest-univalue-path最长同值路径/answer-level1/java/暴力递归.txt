[@liouliooo](/u/liouliooo/)感谢贡献

	暴力求解，将当前节点作为最长路径的根节点，然后依次向下搜索,是自顶向下的搜索方法，
	但是会有很多节点被重复搜索，所以时间复杂度很高。用count记录搜索过程中的最长路径。
```
代码块
<!-- Definition for a binary tree node.
 public class TreeNode {
	public int val;
	public TreeNode left;
	public TreeNode right;
	public TreeNode(int x) { val = x; }
} -->

public class Solution  {
	//暴力求解，将当前节点作为最长路径的根节点，然后依次向下搜索,
	//是自顶向下的搜索方法，但是会有很多节点被重复搜索，所以时间复杂度很高。
	//用count记录搜索过程中的最长路径。

			public int longestUnivaluePath(TreeNode root) {
		        // 自顶向下，暴力搜索.
		        int count = 0;
		        search_top_down(root, count);
		        return count;
		    }
		    
		    // 搜索当前节点，以当前节点为最长路径的根进行搜索.
		   public int bfs(TreeNode root, int count)
		    {
		        int left = 0, right = 0;
		        // 1.递归返回条件
		        if (root == null) { return left; }

		        // 2.递归体
		        if (root.left != null && root.left.val == root.val)
		        {
		        	left = bfs(root.left,count);
		        }
		        if (root.right != null && root.right.val == root.val)
		        { right = bfs(root.right, count); }

		        // 3.合并子问题.
		        int current = max(left, right) + 1;
		        count = max(count, left+right);  // 更新count，注意是路径长度，不是节点个数.
		        return current;
		    }

		    private int max(int left, int right) {
			if(left >= right)
				return left;
			return right;
		}

			// 搜索整棵树
		    void search_top_down(TreeNode  root, int count)
		    {
		        // 1.返回条件
		        if (root == null) { return; }
		        
		        // 2.搜索当前节点.
		        bfs(root, count);

		        // 3.搜索子树
		        search_top_down(root.left, count);
		        search_top_down(root.right, count);
		    }
		};

```

			