根据平衡二叉树的定义：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。

如果 `root == null` 则是一个平衡二叉树，重点是左右子树的高度差不超过1，且左右子树也是平衡二叉树。（递归的数据结构）

讨论中有[1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5]是否是一个二叉树：

根据结构：

![QQ截图20191031143353.png](https://pic.leetcode-cn.com/3968d38a15af33579ad1cd1fc6d1c3cd7bd8f9a552fb11fc3339e07ec6a2399f-QQ%E6%88%AA%E5%9B%BE20191031143353.png)

root的左右子树高度分别为4和3，依次递归，root.left的左右子树高度为3和2，root.right的左右子树高度为2和1...是一个平衡二叉树。

刚开始代码写的是

```
public class IsBalanced {
	public boolean isBalanced(TreeNode root) {
		if (root == null) return true;
		
		int left = treeHeight(root.left);
		int right = treeHeight(root.right);
		
		int tmp = Math.abs(left - right);
		return tmp <= 1;
	}
	
	private int treeHeight(TreeNode root) {
		if (root == null) return 0;
		
		return Math.max(treeHeight(root.left), treeHeight(root.right)) + 1;
	}
}
```

测试用例：[1,2,2,3,null,null,3,4,null,null,4]报错，因为忽视了左右子树也是一颗平衡二叉树这个递归条件。
![QQ截图20191031142808.png](https://pic.leetcode-cn.com/1cc0e2a2fc5c6d8e6c099eb5cf4a63b922ba87adb85e64fae503e6fbf4e100d7-QQ%E6%88%AA%E5%9B%BE20191031142808.png)
很明显，root的左右子树已经不是平衡二叉树了。

改进代码之后：

```
public class IsBalanced {
	public boolean isBalanced(TreeNode root) {
		if (root == null) return true;
		
		int left = treeHeight(root.left);
		int right = treeHeight(root.right);
		
		int tmp = Math.abs(left - right);
		return isBalanced(root.left) && isBalanced(root.right) && tmp <= 1;
	}
	
	private int treeHeight(TreeNode root) {
		if (root == null) return 0;
		
		return Math.max(treeHeight(root.left), treeHeight(root.right)) + 1;
	}
}
```

难受的是，这个时间复杂度也太高了。

> 执行用时 :94 ms, 在所有 java 提交中击败了5.08%的用户
> 内存消耗 :47.5 MB, 在所有 java 提交中击败了5.00%的用户

最优解,参考别人的代码，如下：

```
public class IsBalanced {
	private int balance(TreeNode root){
	    if(root == null) return 0;
	    
	    int left = balance(root.left);
	    if(left == -1) return -1;
	    
	    int right = balance(root.right);
	    if(right == -1) return -1;
	    
	    if(Math.abs(left - right) > 1) return -1;
	    
	    return (left > right ? left : right) + 1;
	}
	
	public boolean isBalanced(TreeNode root) {
	    return balance(root) != -1;
	}
}

```

写时一时爽，运行火葬场，还需要多加思考，优化递归思路。