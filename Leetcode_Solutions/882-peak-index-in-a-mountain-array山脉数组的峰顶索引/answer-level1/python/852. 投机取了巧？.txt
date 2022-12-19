### 解题思路
我不知道我理解的对不对。
数组中的最大值一定就是山峰，找到山峰的index就行了。

### 代码

```python3
class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        peak = max(A)
        index = A.index(peak)
        return index
```
另一个方法：如果出现当前值小于前一个值，就说明前一个值即为山峰。
```python3
class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        for i in range(1, len(A)):
            if A[i] < A[i-1]:
                return i-1
```
