### 解题思路
1、处理特殊情况：list=[]时，直接加入target，并返回索引0；
2、因为list默认从小到大已排序，故从左到右遍历list：
2.1、比较list的元素与target的大小，相等即返回索引；
2.2、遇到第一个比target大的数并且之前没有等于target的数，则直接插入target到该位置，并返回索引；
2.3、处理最后一个数仍然小于target的情况，将target插入到最后，并返回索引。

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            nums.append(target)
            return 0
        for i in range(len(nums)):
            if nums[i] == target:
                return i
            if nums[i] > target:
                nums.insert(i, target)
                return i
            if nums[len(nums) - 1] < target:
                nums.append(target)
                return len(nums) - 1
```