### 解题思路
先用log10求出有多少位（digi+1），用while也可以替代
然后如果n只有一位就直接输出答案
如果n有多位，判断上一步是否退位back（第一次迭代预设为不退位back=0），退位（back==1）则当前位-1（n%10-back）
再判断当前位（n%10-back）是否为1，如果不是则在输出1（ans_a）的前面添加一个1，否则添加2并记录退位为1.
不是1的话继续判断是否为0看看需不需要退位
每迭代一次后移除n的最后一位，一共迭代floor|log10(n)|次

### 代码

```python3
import math
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        digi=int(math.log10(n))
        back=0
        temp=n
        ans_a=''
        if digi==0:
            return [1,n-1]
        else:
            for i in range(digi):
                if  n%10-back==1:
                    ans_a='2'+ans_a
                    back=1
                else:
                    ans_a='1'+ans_a
                    if n%10-back==0:
                        back=1
                    else:
                        back=0
                n//=10
        ans_a=int(ans_a)
        ans_b=temp-ans_a
        return [ans_a,ans_b]
        
```