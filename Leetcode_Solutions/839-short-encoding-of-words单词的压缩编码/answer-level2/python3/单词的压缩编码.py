### 解题思路
一开始看错还要输出A的索引序列。一直在想，怎么维护这个索引数组，而且有序？
发现只要输出长度。
### 代码
```python
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words.sort(key=lambda i:len(i), reverse=True) #按单词元素长度降序
        res = ''
        for word in words:
            if word+'#' in res:continue
            else: res+= word+'#'
        return len(res)
```