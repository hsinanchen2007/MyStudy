# 一.深度优先
**思路**：每个节点遍历的时候用一个参数给定层数
```python []
class Solution:
	def largestValues(self,root):
		ans=[]
		def dfs(root,depth): #depth表示该结点在给定的树中的层次 根节点是0层
			if root: #None就不需要什么处理了
				if len(ans)!=depth or ans.append(root.val):
					ans[depth]=max(ans[depth],root.val)
				[dfs(i,depth+1) for i in (root.left,root.right)] #前序遍历
		return dfs(root,0) is None and ans #完全可以写成两行dfs(root,0) return ans <- 这边是懒得分行了
```
```golang []
func largestValues(root *TreeNode) (ans []int) {
	max:=func (i,j int) int {
		if i<j {
			return j
		}
		return i
	}
	var dfs func(*TreeNode,int)
	dfs=func (root *TreeNode,depth int) {
		if root!=nil {
			if len(ans)==depth {
				ans=append(ans,root.Val)
			} else {
				ans[depth]=max(ans[depth],root.Val)
			}
			dfs(root.Left,depth+1)
			dfs(root.Right,depth+1)
		}
	}
	dfs(root,0)
	return
}
```

# 二.层序遍历
**思路**：每层的节点值一个个比对过去就是了
```python []
from itertools import chain
class Solution:
	def largestValues(self,root):
		ans,queue=[],[] if not root else [root]
		while queue:
			ans.append(max(i.val for i in queue)) #当前层的最大值
			queue=list(chain.from_iterable((j for j in (i.left,i.right) if j) for i in queue)) #更新->下一层的节点
		return ans
```
```golang []
func largestValues(root *TreeNode) (ans []int) {
	if root!=nil {
		queue:=[]*TreeNode{root}
		for len(queue)!=0 {
			n_queue,max:=make([]*TreeNode,0,len(queue)*2),queue[0].Val
			for _,i:=range queue {
				if v:=i.Val;v>max {
					max=v
				}
				if t:=i.Left;t!=nil {
					n_queue=append(n_queue,t)
				}
				if t:=i.Right;t!=nil {
					n_queue=append(n_queue,t)
				}
			}
			queue=n_queue
			ans=append(ans,max)
		}
	}
	return
}
```
