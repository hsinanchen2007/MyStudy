### 解题思路
统计L,R出现的数量是否平衡，平衡的话就可以输出了

### 代码

```python3
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        reslut = 0
        count = 0
        for i in s:
            if i == 'L':
                count += 1
            else:
                count -= 1
            if count == 0:
                reslut += 1
        return reslut
```