**思路**:能影响到结果的只有每块砖的右端
**注意**:go还是新手 py3也就那样子 以下代码仅供参考 哪里可以改进的还请各位多多指教
```python []
from collections import defaultdict
from itertools import accumulate
class Solution:
	def leastBricks(self,wall):
		situ=defaultdict(int) #用defaultdict更加方便一些 直接+=1就可以了
		_sum_=None
		for i in wall:
			for j in accumulate(i): #因为有现成的可以求解各index对应的前缀和的accumulate 所以就不手动实现了
				situ[j]+=1
			_sum_=j #砖墙的最右端 题目中也提示了这种情况是不可以的 也可以把上两行的accumulate(i)改成accumulate(i[:-1])
		situ[_sum_]=0
		return len(wall)-max(situ.values())
```
```golang []
func leastBricks(wall [][]int) int {
	situ,_sum:=map[int]int{},0
	for _,i:=range wall {
		_sum=0 //更新_sum 从零开始 如果把_sum设置成这里的局部变量 就得每次内循环结束后delete(situ,_sum)
		//当然也可以把下一行的i改成i[:len(i)-1] 就能省去delete()了
		for _,j:=range i { //不知道有没有py的accumulate一样的函数 所以这边手动实现前缀和了
			_sum+=j
			situ[_sum]+=1 //go的map基本上可以说是py的defaultdict
		}
	}
	delete(situ,_sum) //删除砖墙最右端的相关数据
	ans:=0
	for _,i:=range situ { //手动获取最大值(出现次数最多的前缀和) 不知道有没有py的dict的values()
		if i>ans {
			ans=i
		}
	}
	return len(wall)-ans
}
```