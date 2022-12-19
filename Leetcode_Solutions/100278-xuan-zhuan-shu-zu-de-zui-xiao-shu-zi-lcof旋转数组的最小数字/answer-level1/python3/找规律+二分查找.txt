### 方法一：找规律
我们遍历一遍数组，如果发现某个值出现了减小，返回该值即可。

### 代码

```python
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        for i in range(len(numbers) - 1):
            if numbers[i] > numbers[i+1]: return numbers[i+1]
        return numbers[0]
```

### 复杂度分析
- 时间复杂度：$O(N)$。最坏条件下，我们需要遍历整个数组。
- 空间复杂度：$O(1)$。我们未使用任何额外空间`。

### 方法二：二分查找
我们使用二分查找能够加速搜索，
### 代码
```python
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        left, right = 0, len(numbers) - 1
        
        while left < right and numbers[left] >= numbers[right]:
            mid = (left + right) // 2
            if numbers[mid] < numbers[right]: right = mid
            elif numbers[mid] > numbers[right]: left = mid + 1
            else: left += 1

        return numbers[left]
```
### 复杂度分析
- 时间复杂度：$O(logN)$。使用了二分查找。
- 空间复杂度：$O(1)$。使用了 `left`，`right`。