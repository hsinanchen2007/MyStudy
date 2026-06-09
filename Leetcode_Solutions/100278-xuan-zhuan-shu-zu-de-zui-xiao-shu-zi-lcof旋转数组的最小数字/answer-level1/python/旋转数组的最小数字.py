### 解题思路
####分为三种情况
`1.if numbers[m] > numbers[j] 说明m在左排序，则旋转数字范围是[m+1,j]]`
`2.if numbers[m] < numbers[j] 说明m在右排序，则旋转数字在[i,m]`
`3.if numbers[m] == numbers[j]又分为两种情况`:
1. `当m在左排序时`
2. `当m在右排序时`

### 代码

```python
class Solution(object):
    def minArray(self, numbers):
        """
        :type numbers: List[int]
        :rtype: int
        """
        i = 0
        j = len(numbers) - 1
        while i < j:
            m = (i + j) // 2
            #说明m在左排序序列
            if numbers[m] > numbers[j]:
                i = m + 1
            #说明m在右排序序列
            elif numbers[m] < numbers[j]:
                j = m
            else:
                j =j -1
        return numbers[i]
```