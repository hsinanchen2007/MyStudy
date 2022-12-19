
## 迭代实现
广度优先遍历是按层层推进的方式，遍历每一层的节点。题目要求的是返回每一层的节点值，所以这题用广度优先来做非常合适。
广度优先需要用队列作为辅助结构，我们先将根节点放到队列中，然后不断遍历队列。   
![二叉树层次遍历-1.jpg](https://pic.leetcode-cn.com/f3c4f288f91ef62095c5fe6c9132e5efaf774d78ab5a508c4c262a79390a4a3c-%E4%BA%8C%E5%8F%89%E6%A0%91%E5%B1%82%E6%AC%A1%E9%81%8D%E5%8E%86-1.jpg)   
首先拿出根节点，如果左子树/右子树不为空，就将他们放入队列中。第一遍处理完后，根节点已经从队列中拿走了，而根节点的两个孩子已放入队列中了，现在队列中就有两个节点```2```和```5```。
![二叉树层次遍历-2.jpg](https://pic.leetcode-cn.com/4c26563a26b356ec727a90fd52dd5fea8b0fd5d638b3632383c1c0b376297b4d-%E4%BA%8C%E5%8F%89%E6%A0%91%E5%B1%82%E6%AC%A1%E9%81%8D%E5%8E%86-2.jpg)
第二次处理，会将```2```和```5```这两个节点从队列中拿走，然后再将2和5的子节点放入队列中，现在队列中就有三个节点```3```，```4```，```6```。   
![二叉树层次遍历-3.jpg](https://pic.leetcode-cn.com/ffb14166d055e682bab11a985456b6e3281c4089bae8282a5f6f1e9c8c81d8b8-%E4%BA%8C%E5%8F%89%E6%A0%91%E5%B1%82%E6%AC%A1%E9%81%8D%E5%8E%86-3.jpg)
我们把每层遍历到的节点都放入到一个结果集中，最后返回这个结果集就可以了。  
时间复杂度:O(n)  
空间复杂度:O(n)   
代码如下:
```java []
import java.util.*;	
class Solution {
	public List<List<Integer>> levelOrder(TreeNode root) {
		if(root==null) {
			return new ArrayList<List<Integer>>();
		}
		
		List<List<Integer>> res = new ArrayList<List<Integer>>();
		LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
		//将根节点放入队列中，然后不断遍历队列
		queue.add(root);
		while(queue.size()>0) {
			//获取当前队列的长度，这个长度相当于 当前这一层的节点个数
			int size = queue.size();
			ArrayList<Integer> tmp = new ArrayList<Integer>();
			//将队列中的元素都拿出来(也就是获取这一层的节点)，放到临时list中
			//如果节点的左/右子树不为空，也放入队列中
			for(int i=0;i<size;++i) {
				TreeNode t = queue.remove();
				tmp.add(t.val);
				if(t.left!=null) {
					queue.add(t.left);
				}
				if(t.right!=null) {
					queue.add(t.right);
				}
			}
			//将临时list加入最终返回结果中
			res.add(tmp);
		}
		return res;
	}
}
```
```python []
class Solution(object):
	def levelOrder(self, root):
		"""
		:type root: TreeNode
		:rtype: List[List[int]]
		"""
		if not root:
			return []
		res = []
		queue = [root]
		while queue:
			# 获取当前队列的长度，这个长度相当于 当前这一层的节点个数
			size = len(queue)
			tmp = []
			# 将队列中的元素都拿出来(也就是获取这一层的节点)，放到临时list中
			# 如果节点的左/右子树不为空，也放入队列中
			for _ in xrange(size):
				r = queue.pop(0)
				tmp.append(r.val)
				if r.left:
					queue.append(r.left)
				if r.right:
					queue.append(r.right)
			# 将临时list加入最终返回结果中
			res.append(tmp)
		return res
```
   
   
   
## 递归实现
用广度优先处理是很直观的，可以想象成是一把刀横着切割了每一层，但是深度优先遍历就不那么直观了。    
![4.jpg](https://pic.leetcode-cn.com/1df38946dbf6129193e35a5d1ade36e3c91fc68c702c37def6e7ee15d973388d-4.jpg)
我们开下脑洞，把这个二叉树的样子调整一下，摆成一个田字形的样子。田字形的每一层就对应一个list。   
![5.jpg](https://pic.leetcode-cn.com/367726d56045ab65cd9bf34af1f4b98408dfa02669c0d2bb88b4aeb53143cf1f-5.jpg)   
按照深度优先的处理顺序，会先访问节点```1```，再访问节点```2```，接着是节点```3```。
之后是第二列的```4```和```5```，最后是第三列的```6```。
每次递归的时候都需要带一个index(表示当前的层数)，也就对应那个田字格子中的第几行，如果当前行对应的list不存在，就加入一个空list进去。
动态演示如下：
![0203_1.gif](https://pic.leetcode-cn.com/aeed09e12573ec00d83663bb4f77562e8904ac58cdb2cbe6e995f2ac33b12934-0203_1.gif)
时间复杂度:O(N)    
空间复杂度:O(h)，h是树的高度    
代码如下:
```java []
import java.util.*;	
class Solution {
	public List<List<Integer>> levelOrder(TreeNode root) {
		if(root==null) {
			return new ArrayList<List<Integer>>();
		}
		//用来存放最终结果
		List<List<Integer>> res = new ArrayList<List<Integer>>();
		dfs(1,root,res);
		return res;
	}
	
	void dfs(int index,TreeNode root, List<List<Integer>> res) {
		//假设res是[ [1],[2,3] ]， index是3，就再插入一个空list放到res中
		if(res.size()<index) {
			res.add(new ArrayList<Integer>());
		}
		//将当前节点的值加入到res中，index代表当前层，假设index是3，节点值是99
		//res是[ [1],[2,3] [4] ]，加入后res就变为 [ [1],[2,3] [4,99] ]
		res.get(index-1).add(root.val);
		//递归的处理左子树，右子树，同时将层数index+1
		if(root.left!=null) {
			dfs(index+1, root.left, res);
		}
		if(root.right!=null) {
			dfs(index+1, root.right, res);
		}
	}
}
```
```python []
class Solution(object):
	def levelOrder(self, root):
		"""
		:type root: TreeNode
		:rtype: List[List[int]]
		"""
		if not root:
			return []
		res = []
		def dfs(index,r):
			# 假设res是[ [1],[2,3] ]， index是3，就再插入一个空list放到res中
			if len(res)<index:
				res.append([])
			#  将当前节点的值加入到res中，index代表当前层，假设index是3，节点值是99
			# res是[ [1],[2,3] [4] ]，加入后res就变为 [ [1],[2,3] [4,99] ]
			res[index-1].append(r.val)
			# 递归的处理左子树，右子树，同时将层数index+1
			if r.left:
				dfs(index+1,r.left)
			if r.right:
				dfs(index+1,r.right)
		dfs(1,root)
		return res
```
(全文完)   
   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)