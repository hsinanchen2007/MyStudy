1. 首先$a+\frac{1}{b}$的分数形式本就是极简分数，相加之后的数本就不需要通分，其最大公约数为1
2. 相加之后的项$\frac{ab+1}{b}$中的$ab+1$即是下一步迭代过程中的分母
3. $b$就是下一步迭代的累加项，分子是b+ 左移一位数 *(ab+1)

```
class Solution:
    def fraction(self, cont: List[int]) -> List[int]:
        #结果模拟,一个记录分子，一个记录分母
        res = [cont[len(cont)-1],1]
        #迭代
        for i in range(len(cont)-2,-1,-1):
            tmp = res[1]
            res[1] = res[0]
            res[0] = cont[i] * res[1] + tmp
        return res
```

