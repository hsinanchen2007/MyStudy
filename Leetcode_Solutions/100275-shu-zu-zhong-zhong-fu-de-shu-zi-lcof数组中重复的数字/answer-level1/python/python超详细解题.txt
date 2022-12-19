## 解题分析
如果这道题真的在面试中被问到了，一定要问面试官一个问题，对空间复杂度有没有要求，能不能修改原来的结构；

如果面试官说不可以修改数据结构的话，并且空间复杂度可以为O(n)的话，那么这里就要使用哈希表了；

- 遍历整个数组，查看该元素在哈希表中（java中使用HashSet，Python中使用set()）有没有该元素，有的话直接返回，没有的话将这个元素放到哈希表中；

但是题目中指定了一个条件，**所有数字都在 0～n-1 的范围内**，所以我猜面试官应该是想要一种可以修改原数据结构并且空间复杂度可以为O(n)的算法，下标定位算法；

- 我们遍历这个数组，假设当前元素的索引是m，索引所在的元素的值是n，那么我们就要判断m和n是否相等，如果不相等的话，我们就要找到索引为n所在的元素，如果人家索引为n的值本来就是n我们就定为到了重复的数字，返回即可，如果索引为n的值不为n是x，那么我们就把索引n的值置为n，再把元素x放到索引x所在的位置上去；

## 代码
ps：这里笔者使用的python3.7

- 哈希表

	```python
	class Solution:
	    def findRepeatNumber(self, nums: List[int]) -> int:
	        if nums is None or len(nums) == 0:
	            return -1
	        nums_set = set()
	        for num in nums:
	            if num in nums_set:
	                return num
	            else:
	                nums_set.add(num)
	```

- 下标定位法


	```python
	class Solution:
	    def findRepeatNumber(self, nums: List[int]) -> int:
	        if nums is None or len(nums) == 0:
	            return -1
	        for i in range(len(nums)):
	            if nums[i] != i and nums[nums[i]] == nums[i]:
	                return nums[i]
	            elif nums[i] != i and nums[nums[i]] != nums[i]:
	                nums[nums[nums[i]]] = nums[nums[i]]
	                nums[nums[i]] = nums[i]
	```