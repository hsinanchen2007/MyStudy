### 解题思路

按照题意编写即可。

本质上从左往右读，若有 k个连着的数字都是 t，则读 kt, 而不是 t...t (k 个) 

注意到 for 循环最后一段经常会漏掉，特别是这里延后处理：只有当出现不同时，才对上一段进行处理。


### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        current = "1"
        if n == 1:
            return current

        for i in range(1, n):
            new_current = ""
            t = current[0]   # 起始点，第一个数字
            k = 1
            for x in current[1:]:
                if x == t:
                    k += 1
                else:
                    new_current = new_current + str(k) + t
                    t = x
                    k = 1
            new_current = new_current + str(k) + t  # 这里最后一次经常会遗漏
            current = new_current
        return current

```