### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def minArray(self, numbers):
        """
        :type numbers: List[int]
        :rtype: int
        """
        numbers.sort()
        #print(numbers)
        return numbers[0]
```