```
class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        dict1 = {}
        for i,num in enumerate(keyboard):
            dict1[num] = i
        wordList = list(word)
        wordList.insert(0, 0)
        T = 0
        for i in range(1,len(wordList)):
            wordList[i]= dict1[wordList[i]]
            T = T + abs(wordList[i]-wordList[i-1])
        return T
```

思路比较简单，直接把所有键盘键位按字典存起来，然后把word中的字母转换成位置，遍历字母然后作差就行。
