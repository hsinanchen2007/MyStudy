递归求解。
问题可以划分为以下三个子问题：
1.当前字符串长度为1，直接返回该字符串结果。
2.当前字符串只包含一种字符，直接返回该字符串结果。
3.当前字符串大于1，且包含多种字符。则对字符串进行字符计数，对于每种字符只抽取一次作为首字母。减去该字符一次后的剩余字符构造一个子字符串去递归求解排列组合，然后将首字母和子字符串的所有排列组合结果进行拼作为返回结果。
```
from collections import Counter

class Solution:
    def permutation(self, S: str) -> List[str]:
        if len(S) == 1:
            return [S]
        else:
            chr_count = Counter(S)
            if len(chr_count) == 1:
                return [S]
            rets = []
            for c in chr_count:
                sub_str = ''.join([chr * count if chr != c else chr * (count-1)for chr, count in chr_count.items()])
                sub_permutation = self.permutation(sub_str)
                rets += [c + p for p in sub_permutation]
            return rets
```