**有任何不懂的请留言，我会尽力解答**

# 题目：
给定 nums = [11, 2，15，7], target = 9
因为 nums[1] + nums[3] = 2 + 7 = 9
所以返回 [1, 3]

# 第1种最耗时，思路：
拿数组里的第一个数字和后面的数字分别相加，看是否等于target；如果不等于target，那么就继续拿数组里的第二个数字和后面的数字相加；不停的去一个个试...直到等于target，返回这2个数字所在的下标

**前置知识：**
nums = [11, 2，15，7]，里面的数字对应的下标分别是0,1,2,3
for循环嵌套执行顺序：如果一个for循环里还有一个for循环，如果条件不满足，那么里面的for循环会先执行完，外面的for循环才会执行


```
class Solution:
	def twoSum(self,nums,target):
		n = len(nums) # 获取nums的长度，是4
		for x in range(n): # 外层循环先取出下标0，对应着数组里的第一个数字
			for y in range(x+1,n): # 内层循环取出下标1，对应着数组里的第二个数字
				if nums[x] + nums[y] == target: # 如果第一个数字+第二个数字=target
					return x,y # 上面的判断是对的话，那么就返回下标
					break # 并停止程序
				else: # 如果上面的条件不满足的话，内层for循环就会继续取出下标2进行判断...如果都不满足，那么外层for循环就会取出下标1...依次类推
					continue 
```


# 第2种，用1个for循环
直接用target 减去 取出的数字，看结果有没有在数组里
```
class Solution:
	def twoSum(self,nums,target):
		n = len(nums)
		for x in range(n):
			a = target - nums[x]
			if a in nums: # 判断a有没有在nums数组里
				y = nums.index(a) # 有的话，那么用index获取到该数字的下标
				if x == y: 
					continue # 同样的数字不能重复用，所以这里如果是一样的数字，那么就不满足条件，跳过
				else: # 否则就返回结果
					return x,y 
					break
			else: 
				continue # 上面的条件都不满足就跳过，进行下一次循环
```

# 第3种，用字典提高速度
这个是看了别人的图解答案才知道的（https://leetcode-cn.com/problems/two-sum/solution/tu-jie-ha-xi-biao-by-ml-zimingmeng/），把原先的数组转化成字典，通过字典去查询速度就会快很多。下面的代码我变更了顺序，好理解多了，速度也快了一些。
```
class Solution:
	def twoSum(self,nums,target):
		d = {}
		n = len(nums)
		for x in range(n):
			d[nums[x]] = x # 把数组里的数字作为key，下标作为value存到d字典中
			if target - nums[x] in d: # 看另外一个数字有没有在字典里
				return d[target-nums[x]],x # 有的话直接就可以返回value了;没有的话会继续循环
```
经群友指出，上面的写法是错误的。如果先把数组转化成字典的话，target-nums[x]的值很有可能会等于nums[x]，正确的如下：
```
class Solution:
	def twoSum(self,nums,target):
		d = {}
		n = len(nums)
		for x in range(n):
			if target - nums[x] in d:
				return d[target-nums[x]],x
			else:
				d[nums[x]] = x
```
