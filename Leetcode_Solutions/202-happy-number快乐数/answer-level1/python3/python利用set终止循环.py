### 解题思路
若给定数为快乐数，则最终结果为 1，若不是则进入死循环。
因此循环终止条件为 sum = 1；
将每次 sum 值存入 issam 中，利用set去重，若出现重复，则 return False 

### 代码

```python3
class Solution:
    def isHappy(self, n: int) -> bool:
        issam = [n]
        while n != 1:
            a = list(str(n))
            n = 0
            for i in a:
                n += pow(int(i),2)
            issam.append(n)
            if len(issam) != len(set(issam)):
                return False
        return True

```