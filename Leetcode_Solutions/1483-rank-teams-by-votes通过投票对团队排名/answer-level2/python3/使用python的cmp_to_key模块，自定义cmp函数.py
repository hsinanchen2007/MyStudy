### 解题思路
抛砖引玉，python3的排序只有key参数，需要调用cmp_to_key来自定义比较参数。
以votes = ["BCA","CAB","CBA","ABC","ACB","BAC"]为例
首先用如下形式记录各字符得票情况：
    {'B': [2, 2, 2], 'C': [2, 2, 2], 'A': [2, 2, 2]}}

接着先对字典转化为元组，并按字典键排序，会变成这个样子：
    [('A', [2, 2, 2]), ('B', [2, 2, 2]), ('C', [2, 2, 2])]
这一步是为了当得票情况完全相同时能够按字母升序排列。

接着我们写cmp函数，把元组第二个元素转为列表，接着依次比较列表从头至尾的元素。相等就比较下一个。最后可能全都相等造成没有返回值，就需要在for循环后返回一个True。

其实到底返回True还是False主要靠试。
最后把字母连接起来。
[这里有cmp的写法](https://www.cnblogs.com/whaben/p/6495702.html)
### 代码

```python3
from functools import cmp_to_key
class Solution:
    def rankTeams(self, votes) -> str:
        counts = {}
        length = len(votes[0])
        for char in votes[0]:
            counts[char] = [0] * length
        for vote in votes:
            for i, char in enumerate(vote):
                counts[char][i] += 1
        # print(counts)
        counts = sorted(list(counts.items()), key=lambda x:x[0])
        # print(counts)

        def sort_key(x, y) -> bool:
            x, y = list(x[1]), list(y[1])
            for i in range(len(x)):
                if x[i] != y[i]:
                    return y[i]-x[i]
                else:
                    continue
            return True
        counts = sorted(counts, key=cmp_to_key(sort_key))
        # print(counts)
        ans = ''.join([x[0] for x in counts])
        return ans

```