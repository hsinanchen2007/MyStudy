一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 关注交流。

### 解题思路
取出第i个数，全排列其他非i位置的数拼在后面。


### 代码

```python
def helper(s):
    if len(s) == 1:
        return s[0]
    res = []
    for i in range(len(s)):
        l = helper(s[:i] + s[i+1:])
        for j in l:
            res.append(s[i] + j)
    return res

class Solution(object):
    def permutation(self, ss):
        """
        :type s: str
        :rtype: List[str]
        """
        if not ss: return []
        words = list(ss)
        return list(sorted(set(helper(words))))
```