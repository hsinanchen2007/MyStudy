### 思路

**数学**

```
暴力计算每个数的因数个数。
满足四个，就因数相加。
注意：因数不能重复。
```

**时间复杂度:** O(n*max(int(sqrt(x)), 4))，n 为 nums 个数。
**空间复杂度:** O(1)

##### Python3代码

```python
from typing import List

class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        sum = 0
        for x in nums:
            if x == 1 or x == 2 or x == 3:
                continue
            num = 2
            temp = [1, x]
            # 计算因数
            while num ** 2 <= x:  # 用 num^2 <= x 比 num <= sqrt(x) 好
                if len(temp) > 4:
                    break
                if not x % num:
                    if num not in temp:
                        temp.append(num)
                    if int(x/num) not in temp:
                        temp.append(int(x/num))
                num += 1
            # print(temp)
            if len(temp) == 4:
                for _ in temp:
                    # print(_)
                    sum += _
        return int(sum)
```

### GitHub链接

[Python](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/1390-Four-Divisors/1390.py)