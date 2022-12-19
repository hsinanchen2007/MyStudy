### 代码

```python3
from typing import List
from functools import cmp_to_key


class Solution:
    def minNumber(self, nums: List[int]) -> str:
        """
        利用字符比较的特性来解题
        设，有字符串 m 和 字符串 n，那么其拼接成的字符串就为 mn 或者 nm.
        根据题意我们需要得到最小数结果，因此我们需要比较 mn 和 nm 两个字符串，看谁得到的数值最小。
        这个 比较算法，我们可以将字符串转换成数字实现（这在其他语言存在溢出问题），随后比较数字。
        也可以直接 mn 和 nm 两个字符串，因为他们长度相同，按照字符串自身的比较算法，也是根据 ascii 逐位比较。
        因此我们选择第二种方法来实现这个比较，有了这个比较，我们也可以定义 m 和 n 的大小。
        我们定义当 mn > nm 的时候，m > n. 因此我们得到了 关于 m 和 n 的比较算法。
        随后我们再利用这个比较算法，将输入的序列排序，便得到满足题意的序列，随后在拼接成字符串即可。
        """
        def cmp(m: str, n: str) -> int:
            mn = m + n
            nm = n + m
            if mn > nm:
                return 1
            elif mn < nm:
                return -1
            else:
                return 0
        num_strs = list(map(str, nums))
        num_strs = sorted(num_strs, key=cmp_to_key(cmp))
        return ''.join(num_strs)
```