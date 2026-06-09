从左到右遍历求解字串，并记录最长子串长度。
以`abcabcbb` 为例子：
初始化max_sub_length=1
第一个字母`a`开头可以找到的最长子串为：`abc`，此时max_sub_length=3
第二个字母`b`开头可以找到的最长子串为：`bca`，此时max_sub_length保持不变
第三个字母`cc`开头可以找到的最长子串为：`cabb`，此时max_sub_length保持不变
...

代码实现：
```
def lengthOfLongestSubstring(s):
    if len(s)==0:
        return 0
    strings = [w for w in s]
    max_sub_length=1
    for i in range(len(strings)):
        sub_str=[strings[i]]
        sub_length=1
        for j in range(i+1, len(strings)):
            if strings[j] not in sub_str:
                sub_str.append(strings[j])
                sub_length+=1
            else:
                break
        if sub_length>max_sub_length:
            max_sub_length=sub_length
    return max_sub_length

```


