题目要求数字对应字符串的笛卡尔积，已知`xmul(A1, A2 ... Ai)`等价于`xmul(...xmul(A1, A2)...Ai)`，所以可以用一个循环来实现，也可以用reduce。
``` python
from functools import reduce
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not len(digits):
            return []
        def xmul(lst):
            def xmul2(a, b):
                return [i+j for i in a for j in b]
            return reduce(xmul2, lst)
    
        mapa = {
            "0" : "" ,
            "1" : "" ,
            "2" : "abc" ,
            "3" : "def" ,
            "4" : "ghi" ,
            "5" : "jkl" ,
            "6" : "mno" ,
            "7" : "pqrs",
            "8" : "tuv" ,
            "9" : "wxyz" 
        }
        ip = [mapa[i] for i in digits]
        return xmul(ip)

```

上面的写法一些地方写的有点啰嗦，可以适当简化。
``` python
from functools import reduce    
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        return [] if not len(digits) else reduce(lambda x, y : [i+j for i in x for j in y], [ {"0" : "" ,"1" : "" ,"2" : "abc" ,"3" : "def" ,"4" : "ghi" ,"5" : "jkl" ,"6" : "mno" ,"7" : "pqrs","8" : "tuv" ,"9" : "wxyz"}[i] for i in digits])
```