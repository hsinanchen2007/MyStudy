想法：从后面遍历，当是空格时跳过，记录非空格的字符数。
设置了一个res=0 用来记录最后一个单词的个数，res=0即等效于空格字符，遍历中当开始res不等于0了，即开始记录字符了，当再次遇到空格时就可以中断遍历，返回值了。
```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        res = 0
        for c in s[len(s)-1::-1]:
            if c != ' ':
                res += 1
            else:
                if res != 0:
                    break
        return res
```
