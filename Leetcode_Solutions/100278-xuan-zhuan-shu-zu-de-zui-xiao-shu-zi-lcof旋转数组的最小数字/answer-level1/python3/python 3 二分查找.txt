### 解题思路
二分查找


### 代码

```python3
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        if not numbers:return numbers
        left,right=0,len(numbers)-1
        while left< right-1: #迭代到只剩下2个元素时，则2个元素中的最小值就为最小元素
            mid=(left+right)//2
            if numbers[mid]>numbers[right]:
                left=mid
            elif numbers[mid]<numbers[right]:
                right=mid
            else: # 相等时，无法判断在那一边，缩小范围
                right=right-1
        return min(numbers[left],numbers[right])
```