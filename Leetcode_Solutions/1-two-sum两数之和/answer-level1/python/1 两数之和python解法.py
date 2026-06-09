### 解题思路1
两个for循环，最占用时间的。

### 代码
```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        len_nums = len(nums)
        for i in range(len_nums):
            for j in range(i+1, len_nums):
                sum_ij = nums[i] + nums[j]
                if sum_ij == target:
                    return [i, j]

```

### 解题思路2
一个for循环，直接用target 减去 取出的数字，看结果有没有在数组里.

### 代码
```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        len_nums = len(nums)
        for index_nums in range(len_nums):
            sub_nums = target - nums[index_nums]
            if sub_nums in nums[index_nums+1:]:
                index_nums_sec = index_nums + 1 + nums[index_nums+1:].index(sub_nums)
                return [index_nums, index_nums_sec]
```

### 解题思路3
直接用字典解决。

### 代码
```python
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