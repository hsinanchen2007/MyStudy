### 解题思路
利用类似栈的方法，把字母和加数都压入栈内。
然后比较后一个字母是否和前一字母相同，如果相同，则加数加1，如果不同，则再压一次栈。

有一个小技巧就是：
在新压入栈之前，把上一个字母的计数先pop出来，转换为str之后再重新压入。这样在最后就可以直接用.join方法来转换输出了。


### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if len(S)<=2:
            return S
        result = []
        result.append(S[0])
        result.append(1)
        for value in S[1:]:
            if value == result[-2]:
                result[-1] += 1
            else:
                num = result.pop()
                result.append(str(num)) # 转换int to str
                result.append(value)
                result.append(1)
        num = result.pop()
        result.append(str(num))
        if len(result) >= len(S):
            return S
        else:
            return "".join(result)        
```