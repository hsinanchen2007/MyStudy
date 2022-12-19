这是一个缩小规模问题，该问题可以通过不断缩小问题规模来解决。设开始下标为$start$，结束下标为$end$，从头到尾扫描整个字符串，当发现有字符$s[j]$与前面字符$s[i]$相同时，有：
$$
res_{start, end} = max(j-start, res_{i+1,end})
$$
于是，我们将问题不断缩小，最终通过一遍遍历得到答案。

这道题目的代码如下：

```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        start = 0
        end = len(s)
        res = 0
        while start < end:
            flag = 1
            se = set()
            for j in range(start, end):
                if s[j] in se:
                    for i in range(start, j):
                        if s[i] == s[j]:
                            res = max(res, j - start)
                            start = i + 1
                            flag = 0
                            break
                else:
                    se.add(s[j])
            if flag:
                res = max(res, end - start)
                break
        return res
```

