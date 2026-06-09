### 解题思路
第一次排序是保证字典序 第二次排序是按照长度 因为python的内建排序本身是稳定的 所以可以保证在第二次排序后的数据仍然符合第一次的字典序

### 代码

```python
class Solution(object):
    def longestWord(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        wordSet = set(words)
        words.sort()
        words.sort(key=len, reverse=True)
        for word in words:
            flag=True
            for i in range(len(word), 0, -1):
                if word[:i] in wordSet:
                    continue
                else:
                    flag = False
            if flag:
                return word
        return ""  

```