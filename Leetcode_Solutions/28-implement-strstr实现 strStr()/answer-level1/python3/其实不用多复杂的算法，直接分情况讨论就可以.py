思路：1.空字符串就是字符串长度为0：返回--1
      2.利用in判断needle是否是haystack的子字符串
      3.遍历字符串，利用切片判断索引的位置
```
 if len(needle)==0:
            return 0
        if needle not in haystack:
            return -1
        for i in range(len(haystack)):
            if haystack[i:i+len(needle)]==needle:
                return i
```
