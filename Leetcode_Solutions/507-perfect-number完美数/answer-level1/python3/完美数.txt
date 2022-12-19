### 解题思路
此处撰写解题思路

### 代码

```python3
import math
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num < 6:  # 1-5都不符合条件，都不是完美数
            return False

        factors = [1]
        end = math.ceil(math.sqrt(num))
        for i in range(2, end+1):
            if (num/i - num//i) == 0:
                factors.append(i)
                factors.append(num//i)  # 获取到所有正因子的列表
   
        if num == sum(set(factors)):  # 需要去重
            return True
        else:
            return False


```