### 解题思路
转换成字符串，然后再判断长度是不是偶数

### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        even = []

        for item in nums:
            if len(str(item)) % 2 == 0:
                even.append(item)
        
        return len(even)
```