        
写，就硬写。
```
class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        return [i for i in words if set(i.lower()).issubset(set("qwertyuiop")) or set(i.lower()).issubset(set("asdfghjkl")) or set(i.lower()).issubset(set("zxcvbnm"))]
```

原代码：
```
class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        new_line = []
        first_line = "qwertyuiop"
        second_line = "asdfghjkl"
        third_line = "zxcvbnm"
        for word in words:
            word_set = set(word.lower())
            if word_set.issubset(set(first_line)) or word_set.issubset(set(second_line)) or word_set.issubset(set(third_line)):
                new_line.append(word)
        return new_line
```
