```
import itertools
from functools import reduce
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        
        # 当 n 为 1 的时候 reduce 函数会报错
        try:
            every_count = reduce(lambda x, y: x * y, range(1, n))   # 使用阶乘算出以每一个数字开头的项目的总个数
            flag = k // every_count                                 # 用 k 除以每一个数字开头的个数得出题解的开头数字的范围（并不是确切的数，具体见下一条注释）
            flag = flag - 1 if flag * every_count == k else flag    # 如果 k 刚好能被every_count整除，那么说明题解的开始数字为 flag，否则为 flag + 1
            temp = [str(i) for i in range(1, n + 1)]
            temp.pop(temp.index(temp[flag]))    # 删除列表中题解的开头数字，保持其它元素相对位置，返回时在字符串的开头加上该数字
            count = k - flag * every_count       # 该变量用以记录新的题解的位置，因为将题解的首字母移动到了列表的起始位置，所以会导致新的题解位置变小
            
            # 将新的列表进行全排列，每次循环将题解的位置计数器减一，知道计数器为零得到题解值
            for each in itertools.permutations(temp, len(temp)):
                count -= 1
                if not count:
                    return str(flag + 1) + ''.join(each)
        except:
            return str(n)
```
