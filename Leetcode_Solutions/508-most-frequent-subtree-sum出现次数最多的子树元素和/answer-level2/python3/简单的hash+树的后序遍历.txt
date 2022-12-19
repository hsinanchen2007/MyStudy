**思路**:就是把每个子树的元素和收集在一起 最后集中处理就行了
**注意**:本人菜鸡+go新手(贴上来算是用来记录自己的成长) 双重debuff加持 py3也就那样 代码仅供参考 哪里有可以改进的地方还请大佬们多多指教
```golang []
type TreeNode struct { //创建树结构的结构体
	Left *TreeNode //左子树
	Right *TreeNode //右子树
	Val int //节点的值
}

func helper(root *TreeNode,res_map map[int]int) int { //这是一个辅助函数 主要就是一个后序遍历
	if root.Left==nil && root.Right==nil { //说明当前节点是叶子节点
		if _,ok:=res_map[root.Val];ok { //对map进行key-value查询的时候会有两个返回值
			res_map[root.Val]+=1
		} else {
			res_map[root.Val]=1
		}
		return root.Val
	} else {
		t_sum:=root.Val
		if root.Left!=nil { //看来以后节点的有无就直接是比较nil了 相当于py的None和java的null
			t_le:=helper(root.Left,res_map)
			t_sum+=t_le
		}
		if root.Right!=nil {
			t_ri:=helper(root.Right,res_map)
			t_sum+=t_ri
		}
		if _,ok:=res_map[t_sum];ok { //这种模式是比较推荐的
			res_map[t_sum]+=1
		} else {
			res_map[t_sum]=1
		}
		return t_sum
	}
}

func findFrequentTreeSum(root *TreeNode) []int {
	if root!=nil {
		situ:=make(map[int]int) //需要哈希 所以先创建一个map[int]int
		helper(root,situ)
		tmp_max:=0 //最大的出现次数 初始化为0
		for _,val:=range situ {
			if val>tmp_max {
				tmp_max=val
			}
		}
		ans:=[]int{} //收集结果 int切片的创建方式1
		for key,val:=range situ {
			if val==tmp_max {
				ans=append(ans,key)
			}
		}
		return ans
	}
	return make([]int,0) //int切片的创建方式2 需要显式指定len cap可以不指定
}
```
```python []
from collections import defaultdict #使用defaultdict可以处理得更加方便
class Solution: 
	def findFrequentTreeSum(self,root):
		if root:
			situ=defaultdict(int)
			def helper(root):
				if not root.left and not root.right:
					situ[root.val]+=1
					return root.val
				_sum_=root.val
				if root.left:
					left_val=helper(root.left)
					_sum_+=left_val
				if root.right:
					right_val=helper(root.right)
					_sum_+=right_val
				situ[_sum_]+=1
				return _sum_
			helper(root)
			goal=max(situ.values())
			return [i for i,j in situ.items() if j==goal]
		return []
```
