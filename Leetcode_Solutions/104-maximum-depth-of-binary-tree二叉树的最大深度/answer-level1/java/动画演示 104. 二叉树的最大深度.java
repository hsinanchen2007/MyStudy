# 递归实现
很多二叉树的题目，用递归写起来就非常简单，这道题就是。
再来分析下递归的两个条件：
1. 递归终止条件：当节点为空时返回
2. 再次递归计算 max( 左节点最大高度，右节点最大高度)+1

终止条件很好理解，节点为空了，就返回0，也就是高度为0。
关键是第二句，这句可能不好理解。
我们看下面这个图，假设节点左边节点这一坨的高度是```x```，右边节点那一坨的高度是```y```
![递归.jpg](https://pic.leetcode-cn.com/4d6aa1066363d0c41c91ad1e5b1b358ed1b988affe56c8ce937fee32d42b1f7f-%E9%80%92%E5%BD%92.jpg)


我们需要比较```X```和```Y```的值谁大，也就是谁的高度更高，假设```X```这一坨更高。当我们得到了```X```的值后，还需要 +1。
+1的原因是，我们只得到了```X```的高度，但是整个树是由根节点，一坨```X```和一坨```Y```组成的。所以为了求得整个树的高度，还需要在```X```的基础上，再加上1，也就多加一个节点(根节点)。
动画演示：
![递归-动态图.gif](https://pic.leetcode-cn.com/cd15ae3fd617f2f1fdb51918950fb321b0b12b70864c336f3951e2243b5bd5fd-%E9%80%92%E5%BD%92-%E5%8A%A8%E6%80%81%E5%9B%BE.gif)


代码实现：
```java []
class Solution {
	public int maxDepth(TreeNode root) {
		//如果节点为空，那么深度就是0
		if(root==null) {
			return 0;
		}
		//否则递归的计算  max(左子树的最大深度，右子树的最大深度)
		//不管左子树，右子树是否为空，他们的父节点肯定是不为空
		//所以计算出的总深度要把父节点也要加上，也就是 +1
		return Math.max( maxDepth(root.left), maxDepth(root.right) ) + 1;
	}
}
```
```python []
	def maxDepth(self, root):
		"""
		:type root: TreeNode
		:rtype: int
		"""
		# 如果节点为空，那么深度就是0
		if(not root):
			return 0
		# 否则递归的计算  max(左子树的最大深度，右子树的最大深度)
		# 不管左子树，右子树是否为空，他们的父节点肯定是不为空
		# 所以计算出的总深度要把父节点也要加上，也就是 +1
		return max( self.maxDepth(root.left), self.maxDepth(root.right) ) + 1
```



# 迭代实现
迭代实现其实就是广度遍历，遍历每一层的节点高度，然后求得最深的一个节点的高度，就是整个树的高度了。
![queue_1.jpg](https://pic.leetcode-cn.com/671010921d2d73140b8dd4f139b244ab3dd8d4b8e7b907e01a062cc978ab374e-queue_1.jpg)

上图中，我们假设每个节点都有一个附加参数key，key就是节点的高度，当遍历完整个树后，就可以求得最大的那个key了。
动画演示：
![队列-动态图.gif](https://pic.leetcode-cn.com/cb1797d00018c3e27281530ea7ca59d564e821c514b42737de49eeaa9f7ab1cf-%E9%98%9F%E5%88%97-%E5%8A%A8%E6%80%81%E5%9B%BE.gif)

代码实现：
```java []
class Solution {
	//自定义一个Pair对象，用来保存(栈深度，节点)
	class Pair {
		final int cur_depth;
		final TreeNode node;
		Pair(int cur_depth,TreeNode node) {
			this.cur_depth = cur_depth;
			this.node = node;
		}
	}

	public int maxDepth(TreeNode root) {
		if(root==null) {
			return 0;
		}
		Stack<Pair> stack = new Stack<Pair>();
		//将(1,root)加入栈后不断遍历栈
		stack.add(new Pair(1,root));
		int max_depth = 0;
		while(!stack.empty()) {
			//首先从栈中弹出元素
			Pair p = stack.pop();
			int cur_depth = p.cur_depth;
			TreeNode node = p.node;
			//如果弹出的节点不为空
			if(node!=null) {
				//比较这个节点的深度和depth的大小
				max_depth = Math.max(max_depth,cur_depth);
				//将 (当前深度+1，left)放入栈中
				stack.add(new Pair(cur_depth+1,node.left));
				//同理将(当前深度+1,right)放入栈中
				stack.add(new Pair(cur_depth+1,node.right));
			}
		}
		return max_depth;
	}
}
```
```python []
class Solution(object):
	def maxDepth(self, root):
		"""
		:type root: TreeNode
		:rtype: int
		"""
		if(not root):
			return 0
		stack = [(1,root)]
		depth = 0
		# 将(1,root)加入栈后不断遍历栈
		while stack:
			# 首先从栈中弹出元素
			cur_depth,node = stack.pop()
			# 如果弹出的节点不为空
			if node:
				# 比较这个节点的深度和depth的大小
				depth = max(cur_depth,depth)
				# 将 (当前深度+1，left)放入栈中
				stack.append((cur_depth+1,node.left))
				# 同理将(当前深度+1,right)放入栈中
				stack.append((cur_depth+1,node.right))
	return depth
```
(全文完)
   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)