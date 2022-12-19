### 解题思路
首先准备两个列表，一个a用来装无重复元素，一个b用来装无重复元素的个数。
遍历字符串s, 当无重复元素时将其append到列表中，并记录该列表的长度到b列表中。
一旦遇到重复元素，就将a列表中该重复元素及之前的所有片段全部切除，继续后面的遍历，直到结束。
最后将b列表（也就是记录了能存在的不重复元素个数的列表）排序，取最大值即可。

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s)>=1:
            a,b = [],[]
            for i in s:
                if i not in a:
                    a.append(i)
                    b.append(len(a))
                else:
                    index = a.index(i)
                    a = a[index+1:]
                    a.append(i)
            b.sort()
            return b[-1]
        else:
            return len(s)

```