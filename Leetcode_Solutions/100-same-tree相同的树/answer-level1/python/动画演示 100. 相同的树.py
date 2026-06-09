# 迭代解法
首先用一个栈来保存根节点p，q。接着不断遍历这个栈。   
首先从栈中拿出两个元素进行比较，如果这两个元素不等(一个是空一个不为空，或者两个节点的值不等)，就直接返回false。   
如果这两个节点的值相等，就继续把p节点的左孩子,q节点的左孩子放入栈中；再把p节点的右孩子，q节点的右孩子放入栈中。   
重复这个步骤，直到栈为空。   
如果整个循环遍历完了，说明两个树的元素都是相等的，返回true。   
以下图为列，我们首先将p，q的根节点放入栈中   
![1573533962(1).jpg](https://pic.leetcode-cn.com/5372989bb3510db2374696ec3debd41ae33e4b75a354c1e2298286b6e6689b60-1573533962\(1\).jpg)
   
接着从栈中弹出两个元素比较(也就是刚放入的p节点1和q节点1)，如果这两个元素相等，就再将他们的左孩子(p的2，q的2)，右孩子(p的3，q的3)都放入栈中。
![1573533971(1).jpg](https://pic.leetcode-cn.com/3bc2f1bb4e2858c54caa974c3776d5f1da5b6e1f30fc2bf12ec6b65919223520-1573533971\(1\).jpg)
   
整个代码的时间复杂度是O(n)，空间复杂度是O(n)。
遍历过程如下：
1. 根节点p的1，q的1相等，放入左孩子，右孩子
2. 弹出右孩子p的3，q的3，相等，再次放入左右孩子(3的左右孩子是空)
3. 弹出两个空元素相等返回true
4. 弹出两个空元素相等返回true
5. 弹出右孩子p的2，q的2，相等，再次放入左右孩子(3的左右孩子是空)
6. 弹出两个空元素相等返回true
7. 弹出两个空元素相等返回true
8. 循环结束，最后返回true
   
代码实现：
```java []
class Solution {
	public boolean isSameTree(TreeNode p, TreeNode q) {
		//用栈来保存p和q遍历时的节点
		Stack<TreeNode> stack = new Stack<TreeNode>();
		stack.add(p);
		stack.add(q);
		while(!stack.isEmpty()) {
			//首先比较当前的两个节点
			TreeNode a = stack.pop();
			TreeNode b = stack.pop();
			//果a和b都为空就继续下一轮比较
			if(a==null && b==null) {
				continue;
			}
			//如果a和b相同，则将a的left和b的left
			//以及a的right，b的right都放入栈中
			if(a!=null &&  b!=null && a.val==b.val) {
				stack.add(a.left);
				stack.add(b.left);
				stack.add(a.right);
				stack.add(b.right);
			//否则就直接返回错误	
			} else {
				return false;
			}
		}
		//如果循环比较结束，说明p和q是相同的
		return true;
	}	
}
```
```python []
class Solution:
	def isSameTree(self, p, q):
		# 用栈来保存p和q遍历时的节点
		stack = [(p,q)]
		while stack:
			# 首先比较当前的两个节点
			a,b = stack.pop()
			# 如果a和b都为空就继续下一轮比较
			if not (a or b):
				continue
			# 如果a和b相同，则将a的left和b的left
			# 以及a的right，b的right都放入栈中
			if a and b and a.val==b.val:
				stack.append((a.left,b.left))
				stack.append((a.right,b.right))
			# 否则就直接返回错误
			else:
				return False
		# 如果循环比较结束，说明p和q是相同的
		return True
```
   
   
   
# 递归解法
写递归函数，一定要先想好递归的终止条件，以及递归函数内需要做什么。
1. 终止条件：p节点和q节点都为空或者两者之一为空，或者两者值不等
2. 再次比较p节点和q节点的左孩子，以及比较p节点和q节点的右孩子

代码时间复杂度是O(n),空间复杂度是O(n)。
![动态图.gif](https://pic.leetcode-cn.com/213d0b6f311a8d2daa64658cfc67e5f5fbde3b29d8a674d08817a1cafdc07203-%E5%8A%A8%E6%80%81%E5%9B%BE.gif)
   
代码实现：
```java []
class Solution {
	public boolean isSameTree(TreeNode p, TreeNode q) {
		//如果p和q都为空就返回True
		if(p==null && q==null) {
			return true;
		}
		//反之，如果p和q有一个不为空就返回False
		if(p==null || q==null) {
			return false;
		}
		//如果p的值 != q的值，也返回False	
		if(p.val!=q.val) {
			return false;
		}
		//递归比较p的左节点和q的左边点，再递归比较p的右节点和q的右节点	
		return isSameTree(p.left,q.left) && isSameTree(p.right,q.right);
	}
}
```
```python []
class Solution(object):
	def isSameTree(self, p, q):
		"""
		:type p: TreeNode
		:type q: TreeNode
		:rtype: bool
		"""
		# 如果p和q都为空就返回True
		if not (p or q):
			return True
		# 反之，如果p和q有一个不为空就返回False
		if not (p and q):
			return False
		# 如果p的值 != q的值，也返回False	
		if p.val!=q.val:
			return False
		# 递归比较p的左节点和q的左边点，再递归比较p的右节点和q的右节点	
		return self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)
```
(全文完)   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)