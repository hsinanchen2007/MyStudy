1.DP 代码写起来比较简单 但是这一条用DP效率不是很好
```
class Solution:
	def maxSumDivThree(self,nums):
		dp=[0,0,0] #dp[i]表示已遍历完成的数字们能组成的最大的sum sum满足sum%3==i 一开始的情况下都置零
		for i in nums:
			new=[i+j for j in dp] #加上一个新数字能组成的较大sum有哪些
			for ele in new:
				dp[ele%3]=max(dp[ele%3],ele) #更新每个index上的sum
		return dp[0]
```
2.数学推理 比较关键的都添加了注释 本人菜鸡 哪里不行还各位多多指教 /(ㄒoㄒ)/~~
```
class Solution:
	def maxSumDivThree(self,nums):
		_all_=0 #表示sum(nums)
		situ={i:list() for i in range(3)} #key是除以3之后的余数 val是nums中各余数所对应的数字组成的list
		for i in nums:
			_all_+=i
			situ[i%3].append(i)
		if _all_%3==0: #明显 如果sum(nums)本身就能整除3 直接返回
			return _all_
		else:
			situ[1].sort() #先进行排序
			situ[2].sort()
			if _all_%3==1: #需要用到situ[1]的最小数字/situ[2]的最小两个数字 -> 这是我们可能找到的最大的能整除3的sum了
				a=_all_-sum(situ[1][:1]) if len(situ[1])>=1 else 0 #注意看len
				b=_all_-sum(situ[2][:2]) if len(situ[2])>=2 else 0
				return max(a,b,0)
			#基本同理 需要用到situ[1]的最小两个数字/situ[2]的最小数字
			a=_all_-sum(situ[1][:2]) if len(situ[1])>=2 else 0
			b=_all_-sum(situ[2][:1]) if len(situ[2])>=1 else 0
			return max(a,b,0)
```
