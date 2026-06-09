**方法一**：维护一个列表，将字符串的字符一个一个存入列表中，每次检查当前字符在列表中是否存在，不存在则加入列表，存在则记录列表长度，然后找到已存在的字符下标，把列表从此处截断，向后继续延伸，直至最后一个字符。
```python []
    def lengthOfLongestSubstring(self, s):
        length = 0
        tempList = []
        for i in range(len(s)):
            if s[i] in tempList:
                length = max(length,len(tempList))
                index = tempList.index(s[i])
                tempList = tempList[index + 1:len(tempList)]
            tempList += s[i]
        return max(length,len(tempList))
```


**方法二**：其实可以不用列表，只记录下标即可，节省空间Max。
```python []
    def lengthOfLongestSubstring(self, s):
        length,left,right = 0,0,0
        for i in range(len(s)):
            if s[i] in s[left:right]:
                length = max(length,right-left)
                left = s[left:right].index(s[i])+left+1
            right += 1
        return max(length,len(s)-left)
```
