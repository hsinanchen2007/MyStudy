### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # 先将数组排序
        nums.sort()
        # 因为是从0开始的排序，依次增长1，所以下标和下标当前数应该是相等的
        for i in range(len(nums)):
            # 如果不相等，则返回当前值的下标
            if i != nums[i]:
                return i
        # 如果一直相等，则返回数组长度
        return len(nums)
```
时间复杂度：O(n\log n)O(nlogn)。由于排序的时间复杂度为 O(n\log n)O(nlogn)，扫描数组的时间复杂度为 O(n)O(n)，因此总的时间复杂度为 O(n\log n)O(nlogn)。
空间复杂度：O(1) O(1) 或 O(n)。空间复杂度取决于使用的排序算法，根据排序算法是否进行原地排序（即不使用额外的数组进行临时存储），空间复杂度为 O(1) 或 O(n)O。

