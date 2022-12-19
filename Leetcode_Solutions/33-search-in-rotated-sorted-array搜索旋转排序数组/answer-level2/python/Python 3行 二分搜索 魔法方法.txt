```python
class Solution:
    def search(self, nums, target):
        self.__class__.__getitem__ = lambda self, m: not(target < nums[0] <= nums[m] or nums[0] <= nums[m] < target or nums[m] < target <= nums[-1])
        i = bisect.bisect_left(self, True, 0, len(nums))
        return i if target in nums[i:i+1] else -1
```
作出数列的函数图像，可以看作是一个含断点的局部递增函数，形如闪电，前面一段总是比较高

python 中 bisect 模块针对的是 list, 如果直接构造 list，相当于遍历所有元素，时间复杂度为 O(N) 而不是 O(logN)，因此我们修改当前类的魔法方法伪造 list，然后用当前类代替list

用二分搜索时，m 代表 middle，low 代表 low，hi 代表 high，当满足任一条件｛① targe < middle 且 middle 在前一段上 且 target < nums[0] ② target > middle 且 middle 在第一段上 ③ target > middle 且 middle 在第二段上 且 target <= nums[-1]｝时，应该向右搜索，因此 getitem 返回 False。
- 另外还有一种简单的思路：二分法找到断点的位置恢复原始数组，然后正常二分法即可
	```python
	class Solution:
	    def search(self, nums, target):
		lo, hi, k = 0, len(nums) - 1, -1
		while lo <= hi:
		    m = (lo + hi) // 2
		    if m == len(nums) - 1 or nums[m] > nums[m+1]:
			k = m + 1
			break
		    elif m == 0 or nums[m] < nums[m-1]:
			k = m
			break
		    if nums[m] > nums[0]:
			lo = m + 1
		    else:
			hi = m - 1
		i = (bisect.bisect_left(nums[k:] + nums[:k], target) + k) % max(len(nums), 1)
		return i if nums and nums[i] == target else -1
	```
