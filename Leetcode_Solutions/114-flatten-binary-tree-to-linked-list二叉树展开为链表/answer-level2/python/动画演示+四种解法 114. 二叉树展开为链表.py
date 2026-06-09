## 解法1
展开后的链表是```1->2->3->4->5->6```，这个顺序就是二叉树前序遍历的顺序，我们用前序遍历的方式遍历这棵树，将结果保存到一个数组中，再把这个数组中的每个元素前后串联起来就可以了。
![1.jpg](https://pic.leetcode-cn.com/4559c27fd63cdda6c3c4aee740c53a5f86288d77a51e337129ed267f3a1391d3-1.jpg)

时间复杂度:O(N)
空间复杂度:O(N)
   
代码实现:
```java []
class Solution {
	public void flatten(TreeNode root) {
		if(root==null) {
			return;
		}
		LinkedList<TreeNode> res = new LinkedList<TreeNode>();
		//前序遍历整棵二叉树
		dfs(root,res);
		TreeNode head = res.removeFirst();
		head.left = null;
		//遍历链表，将链表中的TreeNode节点前后串联起来
		while(res.size()>0) {
			TreeNode tmp = res.removeFirst();			
			tmp.left = null;
			head.right = tmp;
			head = head.right;
		}	
	}
	
	//前序遍历整棵二叉树，并将遍历的结果放到数组中
	void dfs(TreeNode root, List<TreeNode> res) {
		if(root==null) {
			return;
		}
		res.add(root);
		dfs(root.left,res);
		dfs(root.right,res);
	}
}
```
```python []
class Solution(object):
	def flatten(self, root):
		if not root:
			return
		queue = []
		# 前序遍历整棵二叉树，并将遍历的结果放到数组中
		def dfs(root):
			if not root:
				return
			queue.append(root)
			dfs(root.left)
			dfs(root.right)
		dfs(root)
		head = queue.pop(0)
		head.left = None
		# 遍历链表，将链表中的TreeNode节点前后串联起来
		while queue:
			tmp = queue.pop(0)
			tmp.left = None
			head.right = tmp
			head = tmp
```
   
   
   
## 解法2
解法1用队列作为辅助数据结构，完成二叉树的前序遍历。在解法2中则用```栈```作为辅助数据结构，同样也是来实现前序遍历。   
下面这棵树，我们先将```5```放入栈中，再将```2```放入栈中，然后不断重复这个先右后左的顺序。
```
    1
   / \
  2   5
 / \   \
3   4   6
```
在遍历的过程中，同时也将前后的节点串联起来，当整个遍历结束后，二叉树就变成链表结构了。   
![2.gif](https://pic.leetcode-cn.com/e118df68f78055170590bf41deb9188500a35b89ba6761ae23aedf92b7d82531-2.gif)
时间复杂度:O(N)   
空间复杂度:O(N)   

代码实现:
```java []
class Solution {
	public void flatten(TreeNode root) {
		if(root==null) {
			return;
		}
		Stack<TreeNode> stack = new Stack<TreeNode>();
		stack.add(root);
		TreeNode pre = new TreeNode(-1);
		while(stack.size()>0) {
			//用栈作为辅助数据结构，从栈中弹出元素后
			//先将右节点放到栈中，再将左节点放入栈中，模拟前序遍历
			TreeNode tmp = stack.pop();
			pre.left = null;
			pre.right = tmp;
			//先放入右节点，再放入左边点，顺序不能反了
			if(tmp.right!=null) {
				stack.add(tmp.right);
			}
			if(tmp.left!=null) {
				stack.add(tmp.left);
			}
			pre = pre.right;
		}
	}
}
```
```python []
class Solution(object):
	def flatten(self, root):
		if not root:
			return
		stack = [root]
		pre = TreeNode(-1)
		while stack:
			# 用栈作为辅助数据结构，从栈中弹出元素后
			# 先将右节点放到栈中，再将左节点放入栈中，模拟前序遍历
			tmp = stack.pop()
			pre.left,pre.right = None,tmp
			# 先放入右节点，再放入左边点，顺序不能反了
			if tmp.right:
				stack.append(tmp.right)
			if tmp.left:
				stack.append(tmp.left)
			pre = tmp
```
   
   
   
## 解法3
我们采用后序遍历的方式，也就是 左节点-右节点-打印根节点 这个顺序遍历二叉树。   
当遍历到根节点后，我们对根节点的```左右子树```做一些调整。   
```
    1
   / \
  2   3
```
将```右节点```挂到```左节点的最右边```
```
    1
   / 
  2   
   \   
    3   
```
再将整个```左子树```挂到根节点的```右边```，这样就可以将整棵树变成链表结构了。   
```
    1
     \
      2
       \
        3
```
![3.gif](https://pic.leetcode-cn.com/40b1d7aa9f21276443574bc065d80ad6a6e64cfe2fa733277c1609ec2d58ad5d-3.gif)

时间复杂度:O(N)   
空间复杂度:O(h),h是树高度   

代码实现:
```java []
class Solution {
	public void flatten(TreeNode root) {
		helper(root);
	}
	
	void helper(TreeNode root) {
		if(root==null) {
			return;
		}
		helper(root.left);
		helper(root.right);
		//将右子树挂到 左子树的最右边
		//再将整个左子树挂到根节点的右边
		if(root.left!=null) {
			TreeNode pre = root.left;
			while(pre.right!=null) {
				pre = pre.right;
			}
			pre.right = root.right;
			root.right = root.left;
			root.left = null;
		}
	}
}
```
```python []
class Solution(object):
	def flatten(self, root):
		def dfs(root):
			if not root:
				return
			dfs(root.left)
			dfs(root.right)
			# 将右子树挂到 左子树的最右边
			# 再将整个左子树挂到根节点的右边
			if root.left:
				pre = root.left
				while pre.right:
					pre = pre.right
				pre.right = root.right
				root.right = root.left
				root.left = None
		dfs(root)
```
   
   
   
## 解法4
前序遍历是:打印根节点-左节点-右节点 这样的顺序，如果是:右节点-左节点-打印根节点  这样完全相反的顺序遍历呢？   
这样遍历完之后，正好跟前序遍历是相反的。   
前序遍历完是```1,2,3,4,5,6```，按照这种新的方式遍历其结果是:```6,5,4,3,2,1```。   
既然得到了反向的顺序，那么就可以把前后节点串联起来，当遍历到根节点```1```的时候，整个串联就完成了，二叉树就变成了链表。   
```null<-6<-5<-4<-3<-2<-1```   
![4.gif](https://pic.leetcode-cn.com/6e5a4b61e7220a50fb3f4cdf63fdc6848b216d7b8d97a8e296cd2d23a0e8415d-4.gif)

时间复杂度:O(N)   
空间复杂度:O(h),h是树高度  

代码实现:
```java []
class Solution {
	public void flatten(TreeNode root) {
		helper(root);
	}
	
	TreeNode pre = null;
	void helper(TreeNode root) {
		if(root==null) {
			return;
		}
		//右节点-左节点-根节点 这种顺序正好跟前序遍历相反
		//用pre节点作为媒介，将遍历到的节点前后串联起来
		helper(root.right);
		helper(root.left);
		root.left = null;
		root.right = pre;
		pre = root;
	}
}

```
```python []
class Solution(object):
	def flatten(self, root):
		self.pre = None
		def dfs(root):
			if not root:
				return None
			# 右节点-左节点-根节点 这种顺序正好跟前序遍历相反
			# 用pre节点作为媒介，将遍历到的节点前后串联起来
			dfs(root.right)
			dfs(root.left)
			root.left = None
			root.right = self.pre
			self.pre = root
		dfs(root)
```
(全文完)

**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)