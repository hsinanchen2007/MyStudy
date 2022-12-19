**思路**:见标题
**注意**:本人菜鸡 主要的语句都添加了注释 还请各位多多指教
```python []
class Solution:
	def combinationSum3(self,k,n):
		def helper(n,situ=[]):
			if len(situ)==k:
				if n==0:
					return [situ[:]] #注意要深拷贝一下
				situ.pop() #因为整个过程中用的都是同一个situ 所以需要及时pop()
				return []
			ans=[] #收集结果
			for i in range(situ[-1]+1 if situ else 1,min(n+1,10)): #剪枝
				ans+=helper(n-i,situ+[i])
			if situ: #归到最后的时候会出现situ本身为空的情况 所以要先判断一下
				situ.pop()
			return ans
		return helper(n)
```
```golang []
import "math"
var cnt int
func combinationSum3(k int, n int) [][]int {
	situ:=[9]int{} //创建一个用于中间过程处理的array
	cnt=k //本身是一个不会改变的值如果放在参数里面传递有点浪费 所以直接作为一个全局变量来处理了
	return helper(0,n,situ)
}
func helper(ind,nokori int,situ [9]int) [][]int { //ind表示现在的索引(也就是现在有了几个数字) nokori表示现在的几个数字距离目标还有多远
	if ind==cnt {
		if nokori==0 {
			return append([][]int{},append([]int{},situ[:cnt]...)) //第二个append相当于实现了py3的[:]这种深拷贝
		} else {
			return [][]int{}
		} 
	}
	i:=1
	if ind!=0 { //剪枝1. go里面没有选择运算符 所以只能这样子实现选择运算
		i=situ[ind-1]+1
	}
	end:=int(math.Min(10,float64(nokori+1))) //剪枝2. 注意Min的两个参数都得是float64类型的
	ans:=[][]int{} //收集结果
	for i<end {
		situ[ind]=i
		ans=append(ans,helper(ind+1,nokori-i,situ)...)
		i++
	}
	return ans
}
```
