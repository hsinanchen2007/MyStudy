
在次数不足k次的字符处将字符串分段处理

```python3
from collections import Counter
from re import split


class Solution:

    def longestSubstring(self, s: str, k: int) -> int:
        def helper(s, k):
            if len(s) < k:
                return 0

            # 计算不足k次的字符
            split_chars = ''.join(c for c, v in Counter(s).items() if v < k)

            # 如果不小于k次，直接返回当前长度
            if not split_chars:
                return len(s)
            
            # 分治法
            return max(helper(sub_s, k) for sub_s in split(f'[{split_chars}]', s))

        return helper(s, k)

```