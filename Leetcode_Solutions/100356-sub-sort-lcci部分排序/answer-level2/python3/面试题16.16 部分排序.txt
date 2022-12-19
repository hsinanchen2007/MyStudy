### 解题思路
左右两边同时遍历，左边开始记录小于当前最大值的开始位置和结束位置；右边记录大于当前最小值的最开始和最结束位置，输出为四个位置的最小值和最大值

### 代码

```python3
class Solution:
    def subSort(self, array: List[int]) -> List[int]:
        if not array:
            return [-1, -1]
        left_start, left_end, right_start,right_end = -1, -1, -1, -1
        record = array[0]
        
        for i in range(1, len(array)):
            if array[i] < record:
                if left_start == -1:
                    left_start = i-1
                left_end = i
            else:
                record = array[i]

        record = array[-1]
        for j in range(len(array)-1)[::-1]:
            if array[j] > record:
                if right_end == -1:
                    right_end = j
                right_start = j
            else:
                record = array[j]

        return [min(left_start, left_end, right_start, right_end), max(left_start, left_end, right_start, right_end)]


```