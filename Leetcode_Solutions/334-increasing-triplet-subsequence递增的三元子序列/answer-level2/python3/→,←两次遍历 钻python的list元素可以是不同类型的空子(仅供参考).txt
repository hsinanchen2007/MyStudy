思路：题目可以抽象理解为存在n 满足：min(nums[:n])<nums[n]<max(nums[n+1:])
注意：这是我一开始的想法 因为本质钻空子 所以我不推荐 如果能为python用户提供一些小的帮助就可以了(其他大多语言不适用)
```
class Solution:
	def increasingTriplet(self,nums):
		legt=len(nums)
		if legt<3:
			return False
		curr_min=nums[0]
		for i in range(1,legt): #从左向右找最小值
			t=nums[i]
			if t>curr_min:
				nums[i]=str(t) #如果不是目前为止最小的数字 则将其转化为str的形式
			else:
				curr_min=t #更新一下当前的最小值
		curr_max=int(nums[-1]) #以下从右往左找最大值 同理
		for i in range(legt-1,-1,-1):
			t=nums[i]
			try:
				if t>curr_max:
					curr_max=t
			except TypeError: #str和int不可以比较大小
				t=int(t)
				if t<curr_max: #满足我所说的条件 直接return True
					return True
				curr_max=t
		return False
```
更新：以下是比较规范的解法 上述解法通过之后借鉴了powcai大佬的题解完成
```
class Solution:
	def increasingTriplet(self,nums):
		first,second=[float("inf")]*2 #python中的极大值
		for i in nums:
			if i>second:
				return True
			elif first>i: #保留的first越小 越有可能出现满足条件的子序列
				first=i
			elif first<i<second: #同上 这俩就是在极力压缩first,second的数值
				second=i
		return False
```
