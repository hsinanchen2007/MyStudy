### 解题思路
此处撰写解题思路
1. 数组元素从1开始，如果只有1个元素，不处理。
2. 定义计数器来统计相邻元素个数。
3. 定义新变量，记录新数组及对应元素。
4. 将1到新数组长度的所有值，赋值给老数组，截断输出长度。
### 代码

```python3
from typing import List
class Solution:
    def compress(self, chars: List[str]) -> int:
        num = 1
        temstr = chars[0]
        for i in range(1, len(chars)):
            # 如果相邻2个元素值相同，则+1
            if chars[i] == chars[i - 1]:
                num += 1
                # 最后一个元素和num统计，感觉还有更好的方式，没想出来
                if i == len(chars) - 1:
                    temstr += str(num)
            # 相邻2个元素不同的情况
            else:
                # 中间元素只有1个的情况
                if num == 1:
                    temstr += chars[i]
                # 元素不止一个的情况
                else:
                    temstr += str(num)
                    temstr += chars[i]
                    # 还原计数器，
                    num = 1
        # 字符串赋值给列表
        for i in range(1,len(temstr)):
            chars[i] = temstr[i]
        # 截断
        chars = chars[:len(temstr)]
        return len(chars)
```