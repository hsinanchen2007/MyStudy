### 解题思路
1、实现子函数：输入n-1的字符串，得到n的字符串；
2、循环调用子函数，得到第n个序列的字符串，具体见代码实现。

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"

        def say(input_str):
            count = 0
            out_s = ""
            for i in range(len(input_str)):
                if i == 0:
                    count = 1
                if i > 0:
                    if input_str[i] == input_str[i - 1]:
                        count = count + 1
                    else:
                        out_s = out_s + str(count) + str(input_str[i-1])
                        count = 1
                if i == len(input_str) - 1:
                    out_s = out_s + str(count) + str(input_str[i])
            return out_s
        input_s = "1"
        output_s = ""
        for i in range(1, n, 1):
            output_s = say(input_s)
            input_s = output_s
        return output_s
```