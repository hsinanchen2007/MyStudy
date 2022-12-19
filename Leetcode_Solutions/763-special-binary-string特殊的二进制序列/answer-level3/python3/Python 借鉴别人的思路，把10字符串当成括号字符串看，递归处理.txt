![image.png](https://pic.leetcode-cn.com/1b264c25247021a35b5cfbced0debca463917e2c6042fc2f8c764e8ebadb55e0-image.png)


```

'''
题目定义的字符串其实可以看成一个括号匹配的字符串， 1代表左括号，0代表右括号
任何合法的括号字符串一定最左边是左括号，最右边是右括号，但是中间的内容是可变动的

中间可以切成多段合法的子括号字符串，如果中间的字符串没法切成合法的子括号字符串
那交换本身也就不可能了，当前字符串就是字典序最大的，也是字典序最小的

切割的时候每个子串都应该是找以某个位置开始最短的合法括号子串，因为如果两个合法的括号子串前后
接在一起作为一个子串的话，等于认定了这两个子串的顺序不可交换，可能会漏掉最优解

把子串序列找到之后，子串递归进行处理，让每一个子串自己通过交换变成最大的，然后对变化之后的子串序列
进行降序排序，重新前后拼起来作为新字符串，回溯到最开始一层，拼回来的字符串就是字典序最大的

'''

from functools import lru_cache
class Solution:

    @lru_cache(typed=False)
    def makeLargestSpecial(self, S: str) -> str:
        if S == '10':
            return '10'

        parts = []  # 切分出来的子串
        i = 0
        while i < len(S):
            j = i
            cnt = 0
            while j < len(S):
                cnt += 1 if S[j] == '1' else -1
                if cnt < 0:
                    return S    # 中间只要发现无法切割成合法括号字符串的情况，整个字符串都不是一个合法的括号字符串，交换子串也无从谈起，直接向上一层返回字符串本身
                if cnt == 0:
                    break

                j += 1

            parts.append(S[i: j+1])
            i = j+1

        if len(parts) == 1:
            return '1' + self.makeLargestSpecial(parts[0][1:-1]) + '0'
        else:
            return ''.join(sorted([self.makeLargestSpecial(part) for part in parts], reverse=True))
```
