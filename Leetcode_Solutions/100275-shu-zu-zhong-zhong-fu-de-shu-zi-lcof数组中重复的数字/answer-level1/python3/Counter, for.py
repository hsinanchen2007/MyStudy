### 解题思路
![image.png](https://pic.leetcode-cn.com/6c314d3d2c191a2db78b726e907e670e5d6e9792c6eeb0f17b9a2cfd67ed28ab-image.png)


### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        from collections import Counter
        for k,v in Counter(nums).items():
            if v > 1: return k
        return None
```