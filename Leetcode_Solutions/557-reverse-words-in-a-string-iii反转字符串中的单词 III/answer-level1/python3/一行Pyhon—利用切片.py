和另一个两次倒序的解法不同，直接对单词倒序了放回，更清晰一些
```
def reverseWords(s) -> str:
    # 分割完倒序直接放进
    return ' '.join( [ss[::-1] for ss in s.split(' ')] )
```
先通过split和分隔符' '提取出单词，
再通过切片[::-1]的特性将单词倒序，
最后通过.join连接字符串