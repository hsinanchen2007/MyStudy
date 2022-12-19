### 解题思路

不快乐的数会出现无限循环，定义一个list存下每次计算的结果，如果结果二次出现，就返回false，如果出现结果为1，返回true

不过这个解法好像效率并不高

### 代码

```python3
class Solution:
    def isHappy(self, n: int) -> bool:
        res_list = []
        def method(a):
            if a == 1:
                return True
            res = 0
            for i in str(a):
                res += int(i)**2
            if res in res_list:
                return False
            else:
                res_list.append(res)    
            return method(res)
        return method(n)
```