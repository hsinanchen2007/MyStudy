### 解题思路
取模运算这里需要想清楚。


### 代码

```python3
class Solution:
    def convertToTitle(self, n: int) -> str:
        # 本质就是 10进制 转换为 26 进制数
        num2str = "ZABCDEFGHIJKLMNOPQRSTUVWXY"
        result = ""

        while n>0: # 如果上面没有换， 这里换成(n-1) % 26 也对。
            result += num2str[n%26]  # 因为周期是 [1-26], 必然是 %26， 而不是 %25 或者 %27
            n = (n-1)//26
        return result[::-1]   # 52 又不对了。
```