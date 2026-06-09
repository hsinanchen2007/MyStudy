### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    @staticmethod
    def getLeastNumbers(arr, k) :
        arr = sorted(arr)
        return arr[:k]

```