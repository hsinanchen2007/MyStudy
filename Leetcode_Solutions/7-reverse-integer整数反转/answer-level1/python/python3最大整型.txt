### 解题思路
python3最大整型是2^63,所以还能简化下

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        int_max = 2**31-1
        int_min = -(2**31)
        rev = 0
        while x != 0:
            pop = -(abs(x)%10) if x < 0 else x%10
            x = int(x/10)
            # x 有可能非常大超过32位，所以要及时停止
            # 停止在距离溢出还有一次循环的时候，所以int_max除以10
            # int_max = 2147483647   int_min = -2147483648 , so pop>7 pop<-8
            # python3 int_max = 2**63 pop大小判断不需要

            rev = rev*10 + pop

            if rev > int_max or rev == int_max:
                return 0
            if rev < int_min or rev == int_min:
                return 0

        return rev
```