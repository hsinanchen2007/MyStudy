### 解题思路
过于简单，没有什么好说的，最后一个值返回一个负就好，这里的算法还是复杂度太高，估计有简单的思路吧

### 代码

```python3
class Solution:
    def sumZero(self, n: int) -> List[int]:
        import random
    # def sumZero(self, n):
        if n == 1:
            return([0])
        else:
            result_rep = True
            while result_rep:
                result = []
                s = 0
                for _ in range(n-1):
                    repeat = True
                    while repeat:
                        i = random.randint(-1000,1000)
                        if i not in result: 
                            result.append(i)
                            s += i
                            repeat = False
                if -s not in result:
                    result.append(-s)
                    result_rep = False
                    return(result)
```