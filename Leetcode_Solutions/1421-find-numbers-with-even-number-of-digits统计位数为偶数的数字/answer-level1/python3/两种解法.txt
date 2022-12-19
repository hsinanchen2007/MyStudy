### 解题思路
计算数字长度即可，
1. 通过math.log来处理
2. 直接转换为字符串来计算长度
3. 
> 注意：使用折叠语句，耗时会长点; 每次提交的耗时并不是一定的

### 代码

```python3
import math
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        # 解法1：用时 120ms
        # return sum(map(lambda x:int(math.log10(x) % 2) == 1, nums))   

        # 解法2：用时 116ms
        # return sum(map(lambda x: len(str(x)) % 2 == 0, nums))

        # 解法3：用时64ms
        c = 0   
        for x in nums:
            if len(str(x)) % 2 == 0:
                c += 1
        return c
```