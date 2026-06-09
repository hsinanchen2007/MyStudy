```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        word, length = False, 0
        for i in range(len(s)-1, -1, -1):
            if s[i] == " " and word == True: return length
            if s[i] != " ": word = True; length += 1
        return length if word else 0
```

思路：
从后向前遍历
为了处理空格，所以使用word来做标记，当遇到非空格时，说明遇到了单词，此时将word设为True，并且length+1
当word为True时如果遇到空格则说明单词结束，返回length
循环结束时，如果word为True则返回length，否则返回0。因为如果这个单词前面没有空格的话，是会走完整个循环的。