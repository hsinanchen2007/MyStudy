### 解题思路
主要就是要清楚str和list两种数据类型的转换.
str -> list:  list(s)
list-> str: ''.join(l)

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        word_list = s.split(' ')
        for i in range(len(word_list)):
            char_list = list(word_list[i])
            char_list.reverse()
            word_list[i] = ''.join(char_list)
        return ' '.join(word_list)
```