1、先删除原始strs里的重复元素
`strs = list(set(strs))`
2、用循环把每个单词的前i位扔到set中，如果set长度>1，就说明不再有公共的了
```
i = 1
while True:
    if len(set([s[:i] for s in strs])) > 1:
        if i == 1: # 应对有空字符串的测试用例
            return ''
        return strs[0][:i-1]
    i += 1
```
完整代码：
```
def longestCommonPrefix(self, strs):
    strs = list(set(strs))
    if len(strs) > 1:
        i = 1
        while True:
            if len(set([s[:i] for s in strs])) > 1:
                if i == 1: # 应对有空字符串的测试用例
                    return ''
                return strs[0][:i-1]
            i += 1
    elif len(strs) == 1:
        return strs[0]
    return ''
```



