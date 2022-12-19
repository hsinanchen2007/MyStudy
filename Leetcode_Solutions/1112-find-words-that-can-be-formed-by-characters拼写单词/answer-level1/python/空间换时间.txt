因为总共有26个小写字母，所以可以建立一个数组，来保存chars中各个字母出现的次数，然后将words中的单词与数组比较。
```
class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        res = 0
        flag = True
        letters = [0] * 26
        for c in chars:
            letters[ord(c) - ord('a')] += 1
        for word in words:
            t = letters[:]
            flag = True
            for w in word:
                if t[ord(w) - ord('a')] != 0:
                    t[ord(w) - ord('a')] -= 1
                else:
                    flag = False
                    break
            if flag:
                res += len(word)
        return res
```
