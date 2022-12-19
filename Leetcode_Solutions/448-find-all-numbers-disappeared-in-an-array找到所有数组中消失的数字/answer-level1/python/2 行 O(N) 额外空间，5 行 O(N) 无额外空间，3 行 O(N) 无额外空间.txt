```Python []
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        s = set(nums)
        return [i for i in range(1, len(nums) + 1) if i not in s]
```
- set 的内部实现为 dict，in 操作时间复杂度为 $O(1)$
- 应题目进阶要求，以下解为 O(N) 时间效率，无额外空间（除了返回数组和中间变量）
```Python []
class Solution:
   def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
	r = [*range(1, len(nums) + 1)]
	for n in nums:
	    r[n - 1] = 0
	for i in range(len(r) - 1, -1, -1):
	    if not r[i]:
		r.pop(i)
	return r
```
- 初始化返回列表为数字 1 ~ n，值=索引+1
- 遍历 nums，并把 r 中出现在 nums 中的值全部置 0，这里实际上利用r为递增序列的特性，近似为一个哈希表
- 删除 r 中所有 0 元素
- 为什么不在遍历 nums 到时候直接删除r中的值？直接删除会影响后续索引的定位，因此需要逆遍历数组
- 此解法初始化的返回数组不是比最终返回数组大，如果需要返回数组占用的空间不变需要使用以下解法
```Python []
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for n in nums:
            nums[abs(n) - 1] = -abs(nums[abs(n) - 1])
        return [i + 1 for i, n in enumerate(nums) if n > 0]
```
- $O(N)$ 时间，无额外空间（除了中间变量），此解参考评论一楼解法，实际上是利用索引把数组自身当作哈希表处理
- 将 nums 中所有正数作为索引i，置 nums[i] 为负值。那么，仍为正数的位置即为（未出现过）消失的数字
  - 原始数组：[4,3,2,7,8,2,3,1]
  - 重置后为：[-4,-3,-2,-7,`8`,`2`,-3,-1]
  - 结论：[8,2] 分别对应的 index 为 [5,6]（消失的数字）

