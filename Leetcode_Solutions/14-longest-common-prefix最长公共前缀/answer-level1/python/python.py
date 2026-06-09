读取第一个字符串中的第1个字符，与剩余的字符串比较第1个字符；

。。。

读取第一个字符串中的第i个字符，与剩余的字符串比较第i个字符；


```PYTHON
def longestCommonPrefix(strs):
    """
    :type strs: List[str]
    :rtype: str
    """
    if len(strs) == 0:
        return ""
    allstr = ""#最长公共前缀
    for i in range(len(strs[0])):
        for mystr in strs[1: ]:
            if len(mystr)==i or strs[0][i] != mystr[i]:
                return allstr
        allstr += strs[0][i]
    return allstr
```

欢迎关注我的博客 www.sbaban.com