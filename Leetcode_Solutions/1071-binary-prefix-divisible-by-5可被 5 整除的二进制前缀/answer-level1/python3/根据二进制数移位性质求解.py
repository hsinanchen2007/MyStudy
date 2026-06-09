解题思路：当只有一位数时，对应第一位数为2的0次方，当有两位数时，第一位为2的1次方，第二位为2的0次方...依此类推，每一次新增的末尾数均为2的0次方，每增加一位数时，将之前已求和的数据x2即可。
代码：
```
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        a = 0
        for i in range (len(A)):
            a = a*2 + A[i]
            if not (a % 5):
                A[i] = True
            else:
                A[i] = False
        return A
```
