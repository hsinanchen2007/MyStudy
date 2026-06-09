// **思路**:两个hash的key都是数字 一个hash用来表示以key作为连续数字段的头时数字段的最大长度 另一个用来表示k所在的最大连续数字段的最小的数字 在遍历nums的值时 同时更新两个hash的状态
// **注意**:本人菜鸡 这种方法效果不算是特别好 主要的语句都添加了注释 以下代码仅供参考 还请大家多多指教
// ```python []
class Solution:
	def longestConsecutive(self,nums):
		if not nums: #很极端的情况
			return 0
		situ=dict() #假设nums[i]在一个连续的数字段中 situ这个dict的键表示的是nums[i]这个数字 值表示的是该数字所在数字段的最小数字的值
		cnt=dict() #cnt这个dict的键表示的也是nums中的任意数字 值表示的是以该数字为头的连续数字串的最大长度
		ans=1 #表示结果 因为极端情况已经被处理掉了 所以可以直接初始化为1
		for i in nums: #遍历nums中的各个数字
			if situ.get(i,None) is None:
				situ[i]=i #初始化 自己就是一个连续的数字段 最小数字的值当然就是自己了
				cnt[i]=1 #初始化 当前数字段只有自己一个数字
				if situ.get(i+1,None) is not None: #说明当前节点后面跟着尾巴
					cnt[i]+=cnt[i+1] #更新 加上后面尾巴的连续数字串的个数
					if cnt[i]>ans: #过程处理1. 在过程中就尽量地去处理最大值的问题
						ans=cnt[i]
					situ[i+1]=i #更新 为了下面展示的跳跃查找真正的头做准备
				if situ.get(i-1,None) is not None: #说明当前节点前面有头
					head=situ[i-1]
					while situ[head]!=head: #一直往前找 直到找到连续段的真正的头 给一个例子 见 🚩
						head=situ[head] #真正的头的头是它自己
					cnt[head]+=cnt[i] #更新
					if cnt[head]>ans: #过程处理2. 同样也是一样的想法 在过程中就去处理一下最大值的问题
						ans=cnt[head]
					situ[i]=head
		return ans
#🚩假如已经有了4,5,6这么一个连续的数字段 6->4 先添加一个数字7 按照我的代码首先是7->6 然后再是通过6这个桥梁实现了7->4
// ```
// ```golang []
func longestConsecutive(nums []int) int {
	if len(nums)==0 { //极端情况 特殊处理
		return 0
	}
	ans:=1 //没有了极端情况 就可以放心初始化为1了
	situ,cnt:=make(map[int]int),map[int]int{}
	for _,v:=range nums {
		if _,ok:=situ[v];!ok {
			situ[v]=v //自己就是
			cnt[v]=1 //只有一个自己
			if _,ok:=situ[v+1];ok {
				cnt[v]+=cnt[v+1]
				situ[v+1]=v //更新尾巴的头
				if cnt[v]>ans { //过程处理1. 省得最后来个max(cnt.values()) <- 虽然golang用不了这俩函数/方法
					ans=cnt[v]
				}
			}
			if _,ok:=situ[v-1];ok {
				head:=situ[v-1]
				for situ[head]!=head { //跳跃式寻找真正的头
					head=situ[head]
				}
				cnt[head]+=cnt[v]
				if cnt[head]>ans { //过程处理2. 跟上面是一样的想法
					ans=cnt[head]
				}
				situ[v]=head //更新
			}
		}
	}
	return ans
}
// ```
