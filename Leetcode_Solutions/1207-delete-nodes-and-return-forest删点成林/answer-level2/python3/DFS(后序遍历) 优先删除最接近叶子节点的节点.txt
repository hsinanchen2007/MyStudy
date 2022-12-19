**思路**：假如说当前节点root是需要删除的 但是root左右子树中还有需要删除的节点roots那么优先删除roots然后再删除root是比较直观明了的 也就是说需要使用到后序遍历
**注意**：基于树的性质其他遍历方式也是可以的 本人菜鸡 主要的语句都添加了注释 一下代码仅供参考 还请大家多多指教
```python []
class Solution:
	def delNodes(self,root,to_delete):
		ans=[]
		dummy=TreeNode(0) #一个哑节点 方便后续的统一处理(比如说root最后可能是要放进ans中去的)
		dummy.left=root
		to_delete=set(to_delete+[0]) #[0]就表示要删除dummy节点 list->set 快速查询
		def dfs(root):
			if root:
				if dfs(root.left):
					root.left=None
				if dfs(root.right):
					root.right=None
				if root.val in to_delete:
					for i in (root.left,root.right):
						if i: #None是不需要的
							ans.append(i)
					return True #True表示要删除当前的root节点 用来提醒其双亲节点来None
			return False
		dfs(dummy)
		return ans
```
```golang []
func delNodes(root *TreeNode,to_delete []int) (ans []*TreeNode) {
	None:=(*TreeNode)(nil)
	dummy:=&TreeNode{0,root,None} //一个哑节点 方便后续的统一处理(比如说root最后可能是要放进ans中去的)
	delete:=map[int]bool{0:true} //[0]就表示要删除dummy节点 []int->map 简单地模拟一下set 实现快速查询
	for _,i:=range to_delete {
		delete[i]=true
	}
	var dfs func (root *TreeNode) bool
	dfs=func(root *TreeNode) bool {
		if root!=nil {
			if dfs(root.Left) {
				root.Left=None
			}
			if dfs(root.Right) {
				root.Right=None
			}
			if delete[root.Val] {
				for _,i:=range []*TreeNode{root.Left,root.Right} {
					if i!=None { //None是不需要的
						ans=append(ans,i)
					}
				}
				return true //true表示当前节点是要删掉的 用来提醒该节点的双亲节点去None
			}
		}
		return false
	}
	dfs(dummy)
	return
}
```
