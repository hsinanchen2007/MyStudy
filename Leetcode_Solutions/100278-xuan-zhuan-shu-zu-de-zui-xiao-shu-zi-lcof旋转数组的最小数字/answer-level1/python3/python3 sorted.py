### 解题思路
  本题内容是排序的考察，python3 可以调用sorted函数排序，取列表首元素即可

### 代码

```python3
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        array=sorted(numbers)
        return array[0]

```