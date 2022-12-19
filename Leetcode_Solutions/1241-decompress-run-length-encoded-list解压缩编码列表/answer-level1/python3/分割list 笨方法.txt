### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        num1 =nums[0::2]
        num2 = nums[1::2]
        num3 = []
        for i in range(len(num1)):
            num3+=(num1[i] * [num2[i]])
        return num3
```