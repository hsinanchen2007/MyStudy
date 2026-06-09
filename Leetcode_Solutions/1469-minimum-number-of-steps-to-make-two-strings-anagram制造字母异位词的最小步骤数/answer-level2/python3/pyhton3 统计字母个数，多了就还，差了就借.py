### 解题思路
统计s和t字符串中字母的数量，然后对s中的每一个字母进行对比
如果t中该字母的个数比s多，那么先看de值是不是零,de值是其他字母在进行补充时积累的量，如果de值不为0，那么消耗de值，同时减少t[key]，如果de值为0，它要继续减少，就最终答案+1，并且使得add值增加
少的情况同理，最终返回res

### 代码

```python3
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        s_dict = collections.Counter(s)
        t_dict = collections.Counter(t)
        add = 0
        de = 0
        res = 0
        for key in s_dict.keys():
            while s_dict[key] != t_dict[key]:
                if s_dict[key] < t_dict[key]:
                    if de:
                        de -= 1
                        t_dict[key] -= 1
                    else:
                        t_dict[key] -= 1
                        res += 1
                        add += 1
                if s_dict[key] > t_dict[key]:
                    if add:
                        add -= 1
                        t_dict[key] += 1
                    else:
                        t_dict[key] += 1
                        res += 1
                        de += 1
        return res

```