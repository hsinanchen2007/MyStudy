### 解题思路
自己手写的代码，增加了一个 add_in 进位变量。
不算太好，过于冗长。

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        add_in = 0
        la, lb = len(a), len(b)
        result = []

        i, j = la-1, lb-1
        while i>=0 and j>=0:
            val = int(a[i]) + int(b[j]) + add_in
            if val == 3:
                add_in = 1
                result.append(1)
            elif val == 2:
                add_in = 1
                result.append(0)
            elif val == 1:
                add_in = 0
                result.append(1)
            else:
                add_in = 0
                result.append(0)
            i -= 1
            j -= 1

        while i>=0:
            val = int(a[i]) + add_in
            if val == 2:
                add_in = 1
                result.append(0)
            elif val == 1:
                add_in = 0
                result.append(1)
            else:
                add_in = 0
                result.append(0)
            i -= 1
        
        while j>=0:
            val = int(b[j]) + add_in
            if val == 2:
                add_in = 1
                result.append(0)
            elif val == 1:
                add_in = 0
                result.append(1)
            else:
                add_in = 0
                result.append(0)
            j -= 1
        if add_in == 1:
            result.append(1)
        result = "".join(str(x) for x in result[::-1])
        return result

            



```