内存打败100%，执行时间44ms。当然这有可能不是最好的解题思路，但是比较直观。
设定一个变量 i 作为次数的纪录，while循环直到数字为0为止。用 % 确定 num 是否为整数，如为整数则除2（i+1），如果不是则减 1（i+1）。最后返回i的值。
```
class Solution:
    def numberOfSteps (self, num: int) -> int:
        i = 0
        while num != 0:
            if num % 2 == 0:
                i+=1
                num = num / 2
            else:
                num -= 1
                i+=1
        return i
```
