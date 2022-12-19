### 解题思路
最开始超时了，设定两个数组，分别记录下一个空缺点和该点是否已经被占用了，然后遍历数组，遇到空缺就填，没有空缺就查下一个空缺点

### 代码

```python3
import json


class Solution:
    def minIncrementForUnique(self, A: list) -> int:
        size = len(A)
        oper = 0
        num_map = [0 for i in range(400000)]
        next_step = [i + 1 for i in range(400000)]
        for one_num in A:
            if num_map[one_num] == 1:
                i = one_num
                while num_map[i] == 1:
                    i = next_step[i]
                num_map[i] = 1
                next_step[one_num] = i
                oper += i - one_num
            else:
                num_map[one_num] = 1
        return oper
```