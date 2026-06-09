思路：假设当前树的叶子节点们为nodes 任选一个叶子节点作为新插入的节点 同时将该节点的两个孩子节点(非None/nil)加入到nodes中去 进去到下一层递归
注意：还有点DFS+BFS的意味 本人菜鸡 效率好像不是很高 主要的语句都添加了注释 还请大家多多指教
```python []
class Solution:
	def BSTSequences(self,root):
		def helper(nodes):
			if not nodes:
				return [[]]
			res=[]
			for i in range(len(nodes)): #用来遍历各个可以添加的节点
				n,v,opts=nodes[i],[nodes[i].val],nodes[:i]+nodes[i+1:] #n:节点 v:节点的值作为唯一元素的[] opts:下一层循环能直接添加的节点
				[opts.append(i) for i in (n.left,n.right) if i] #当前节点被使用掉了 它的俩子节点会作为新的可用节点(要求非None)
				res.extend(v+i for i in helper(opts)) #更新res
			return res
		return helper([root] if root else [])
```
```golang []
func BSTSequences(root *TreeNode) [][]int {
	if root==nil { //不能直接给个[(*TreeNode)(nil)] 特殊情况特殊处理掉
		return [][]int{make([]int,0)}
	}
	return helper([]*TreeNode{root})
}
func helper(nodes []*TreeNode) [][]int {
	if len(nodes)==0 { //已经没有任何可以添加的节点了
		return [][]int{make([]int,0)}		
	}
	res:=make([][]int,0) //保留结果
	for i,j:=range nodes {
		v,opts:=[]int{j.Val},append(nodes[:i:i],nodes[i+1:]...) //这边golang有个底层实现的坑slice的底层数组一直一样
		if t:=j.Left;t!=nil { //接上一行 为了防止出现错误 需要nodes[:i:i]手动提供cap append([]*TreeNode{},nodes[:i]...)也是可以的
			opts=append(opts,t) //opts表示下一层递归可以直接添加的节点 当前的节点被消耗了 它的两个儿子节点出现作为新的可添加节点(条件:不是nil)
		}
		if t:=j.Right;t!=nil {
			opts=append(opts,t)
		}
		for _,i:=range helper(opts) { //更新res
			res=append(res,append(v,i...))
		}
	}
	return res
}
```
