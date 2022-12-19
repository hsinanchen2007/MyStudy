### 解题思路
先找出最大的元素，把它flip到数组最前，然后再flip到最后一位。这个操作相当于selection sort。然后我们需要排序的数组就减少一位。反复如此操作，最后可以得到排序的数组。

呃。。没看到数组元素就是1到N。这样的话可以省去`max(A[:i])`这一步，直接用i代替。

### 代码

```python
class Solution:
    def pancakeSort(self, A: List[int]) -> List[int]:
        i, res = len(A), []
        while i > 0:
            max_idx = A[:i].index(max(A[:i]))
            if max_idx != i-1:
                A[:max_idx+1] = A[:max_idx+1][::-1]
                A[:i] = A[:i][::-1]
                res.extend([max_idx+1, i])
            i +=-1
        return res
```