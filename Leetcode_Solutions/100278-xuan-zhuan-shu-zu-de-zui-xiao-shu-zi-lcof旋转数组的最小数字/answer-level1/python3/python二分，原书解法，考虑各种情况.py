### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        n = len(numbers)
        if n == 0:
            return None
        if numbers[0] < numbers[-1]:
            return numbers[0]
        left = 0 
        right = n-1
        while left < right:
            mid = (left+right) // 2
            if numbers[mid] == numbers[left] == numbers[right]:
                min_ = numbers[0]
                for i in numbers:
                    min_ = min(min_,i)
                return min_
            elif numbers[left] < numbers[right]:
                return numbers[left]
            # 中间元素处于较大序列当中，最小元素在最右边
            elif numbers[mid] >= numbers[left]:
                left=  mid+1
            # 中间元素处于较小序列中，最小元素在左边
            elif numbers[mid] <= numbers[right]:
                right = mid
        return numbers[left]


```