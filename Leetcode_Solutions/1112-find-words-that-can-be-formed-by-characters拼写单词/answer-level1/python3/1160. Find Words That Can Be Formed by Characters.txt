

### 思考 

第一个想法是统计单词中字母的个数，然后遍历词汇表中的单词及其内部的字母，消耗单词中的字母。

--------------

### 方法

```python
"""
1. 每个字符在处理一个单词的拼写时可以用一次，并不是说在词汇表中只能出现一次
2. temp = mapping 是不能拷贝的，赋值的是引用。mapping也会删除
"""
class Solution:
    def countCharacters(self, words, chars):
        length = 0
        # 可以用 Counter 代替
        def build_map(chars):
            mapping = {}
            for char in chars:
                if mapping.get(char):
                    mapping[char]+=1
                else:
                    mapping[char]=1
            return mapping

        for word in words:
            flag = True
            mapping = build_map(chars)#必须重新构建 map
            for c in word:
                count = mapping.get(c)
                if count and count>0:
                    mapping[c]-=1
                else:
                    flag = False
                    break
            if flag == True:
                length+=len(word)

        return length
# Time: O(N) 遍历所有字符串的长度和，不是两层循环就是 N^2
# Space: O(S) 字符集大小决定了 map 的大小，这里 26 个字母 
```

改进
```python
"""
际上不需要逐个检查元素是否存在，我们只需要知道数量是否足够
"""
from collections import Counter
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        dc = Counter(chars)
        res = 0
        for word in words:
            for c in word:
                if word.count(c) > dc[c]:
                    break
            else:#如果没有 break 则走到 else 分支，可以节省一个标记
                res+=len(word)

        return res
        
# Time: O(N) 遍历所有字符串的长度和，不是两层循环就是 N^2
# Space: O(S) 字符集大小决定了 map 的大小，这里 26 个字母 
```