### 解题思路
先在words中的每个词后面都加一个#，然后按照长度由大到小进行排序、
再判断每个子字符串是否存在于当前S中。如果存在则不增加，不存在则增加。
由于已经添加了#，所以能缩写的词都是处在末尾的。

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        ret = ""
        temp = sorted([i + "#" for i in words], key = len, reverse = True)
        for i in temp:
            if i not in ret:
                ret += i
        return len(ret)
```