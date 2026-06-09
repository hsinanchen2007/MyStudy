### 解题思路
此处撰写解题思路

### 代码

```python3
import heapq
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        # 使用快速排序，然后选择前k个最小的点
        def _quick_sort(array):
            if len(array) <= 1:
                return array
            else:
                pivot = array[len(array)//2] # 选择一个基准值
                less = [i for i in array if i < pivot]
                middle = [i for i in array if i == pivot]
                greater = [i for i in array if i > pivot]
                return _quick_sort(less) + middle +  _quick_sort(greater)      
        res = _quick_sort(arr)
        return res[:k]
```