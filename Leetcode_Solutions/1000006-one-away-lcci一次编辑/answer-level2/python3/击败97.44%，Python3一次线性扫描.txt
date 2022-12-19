### 解题思路
我们来讨论一下情况，首先，当两个字串字数差距超过一，这肯定是不符合的。

再来，我们知道删除一个字符和加入一个字符是相反操作，所以如果 first 可以在一次操作变成 second，那么 second 必定也能在一次操作下变回 first，故问题可转换为两个字串可否经由一次变化互相转化。

我们假设 first 比较长， second比较短， 即 len(first) - len(second) == 1，则代表如果 first 可以变成 second，那么一定是经过恰一次的字符删除。 若我们假设 len(second) - len(first) == 1，那么代表 second 变成 first也一定经过恰一次的字符删除，代码如下：

### 代码

```python3
class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        if abs(len(first) - len(second)) > 1: return False
        
        if len(first) < len(second):
            first, second = second, first
            
        # len(first) > len(second)
        
        if len(first) == len(second):
            quota = 1
            for i in range(len(first)):
                if first[i] != second[i]:
                    quota -= 1
                    if quota < 0:
                        return False
            return True
        
        p = q = 0
        quota = 1
        
        while p < len(first) and q < len(second):
            if first[p] != second[q]:
                p += 1
                quota -= 1
            else:
                p += 1; q += 1
                
            if quota < 0:
                return False
            
            
            
        return True
```