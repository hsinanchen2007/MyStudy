### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        learn_words = []#创建变量  
        i = 0 #创建变量
        for word in words:#循环每一个单词
            count = len(word)# 比较
            char = list(chars[:])#切片，对于每一个都要比较
            for letter in word:#
                if letter in char:#
                    char.remove(letter)#
                    i = i + 1#
            if i == count:#比较是否能够学会
                learn_words.append(word)
            i = 0
        res = 0
        for i in learn_words:
            res += len(i)
        return res
```