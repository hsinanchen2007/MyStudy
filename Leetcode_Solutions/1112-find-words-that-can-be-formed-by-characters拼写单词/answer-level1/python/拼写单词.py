### 解题思路
用字典统计chars中字符的个数，对于words中的每一个单词，统计其中出现的字符的个数，如果words中单词的字符出现的次数小于chars中相应字符的次数，则能掌握这个单词

### 代码

```python
class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        dic={}
        for i in chars:
            dic[i]=dic.get(i,0)+1
        length=0
        for word in words:
            flag=1
            for i in set(word):
                if i not in chars or word.count(i)>dic[i]: 
                    flag=0
                    break
            if flag==1:
                length+=len(word)
        return length
```