### 解题思路
        res = 0
        商数不为0，循环继续 while x:
            rem = x % 10 获取余数
            x = x // 10 获取商数
            res = res*10 + rem   
        注意正负数和溢出问题   

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        """
        res = 0
        商数不为0，循环继续 while x:
            rem = x % 10 获取余数
            x = x // 10 获取商数
            res = res*10 + rem   
        注意正负数和溢出问题       
        """
        res = 0
        flag = 0 # flag 为0 表示正数
        if x < 0: # x 为负数
            flag = -1 # 将flag置为-1，表示输入的x是负数
            x = 0 - x # 同时将负数x变为正数
        while x:
            rem = x % 10
            x = x // 10
            res = res*10 + rem

        if flag < 0: # 如果flag小于0，即flag被置为-1，那么说明输入x是一个负数，则颠倒的res要变为负数
            res = 0 - res

        # 判断是否溢出
        if res > 2147483647 or res < -2147483648:
            return 0
        return res
```