### 解题思路
首先对p做了一个小处理，即将p转换为列表，而将'\*'和它前面的字符看做一个整体，比如p = 'a\*b\*c'转换为['a\*', 'b\*', 'c']，这样可以方便后续处理，因为'\*'单独并没有意义。然后就是进行分情况讨论，我觉得这里也可以看作是有限状态机的处理过程，这里需要想明白所有的课处理方式，并在产生不匹配时返回，这样做也可以看做是剪枝。最重要的就是备忘录，这道题的备忘录的意义是显而易见的，而且如果不使用备忘录会使得进行大量的重复计算导致超时。

### 代码

```python
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        len_s = len(s)
        len_p = len(p)
        p_list = []
        i = 0
        while i < len_p:
            if i + 1 < len_p and p[i + 1] == '*':
                p_list.append(p[i] + p[i + 1])
                i += 2
            else:
                p_list.append(p[i])
                i += 1
        print(p_list)
        len_p = len(p_list)
        mem = {}
            
        def get_res(i, j):
            if (i, j) in mem:
                return mem[(i, j)]
            if j == len_p: # 如果模式已经全部匹配
                if i == len_s: # 如果字符串也都已经全部匹配
                    res = True
                else: # 字符串没有完全匹配
                    res = False
            else:
                if len(p_list[j]) == 1: # 普通字符或者'.'
                    if i < len_s and (p_list[j] == '.' or s[i] == p_list[j]):
                        res = get_res(i + 1, j + 1)
                    else:
                        res = False
                else: # 包括*
                    if i < len_s:
                        if p_list[j][0] == '.' or p_list[j][0] == s[i]: 
                            res = get_res(i + 1, j + 1) or get_res(i + 1, j) or get_res(i, j + 1)
                        else:
                            res = get_res(i, j + 1)
                    else:
                        res = get_res(i, j + 1)
            mem[(i, j)] = res
            return res
        return get_res(0, 0)
```