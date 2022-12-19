```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        for i in range(len(nums)-1, 0, -1):
            if nums[i] == nums[i-1]: nums.pop(i)
        return len(nums)
```
- 时间效率O(N^2)空间效率O(1)，逆遍历可以防止删除某个元素后影响下一步索引的定位。
- 每次删除数组元素会引发大量的数据迁移操作，使用以下算法解题效率更高
	```python
	class Solution:
	    def removeDuplicates(self, nums: List[int]) -> int:
		i = 0
		for j in range(1, len(nums)):
		    if nums[j] != nums[i]:
			nums[i + 1] = nums[j]
			i += 1
		return i + 1 if nums else 0
	```
	- 此解法思路同官方题解，时间效率为O(N)
	- 数组完成排序后，我们可以放置两个指针 i 和 j，其中 i 是慢指针，而 j 是快指针。只要 nums[i] = nums[j]，我们就增加 j 以跳过重复项。当我们遇到 nums[j] != nums[i]时，跳过重复项的运行已经结束，因此我们必须把它（nums[j]）的值复制到 nums[i + 1]。然后递增 i，接着我们将再次重复相同的过程，直到 j 到达数组的末尾为止
