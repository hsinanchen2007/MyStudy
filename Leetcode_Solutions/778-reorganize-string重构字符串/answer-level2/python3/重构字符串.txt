### 解题思路
先将字母按数量排序，然后将字母一个一个插入Out中，插入规则为，如果找到两个相邻是一样的
就插入这里，如果Out里没有相邻是一样的则从头开始在一个前后与自己不同的地方插入。
### 代码

```python3
class Solution:
    def reorganizeString(self, S: str) -> str:
        words = [[chr(97+i),0] for i in range(26)]
        for i in range(len(S)):
            words[ord(S[i])-97][1]+=1

        words.sort(key=lambda  x:x[1],reverse = True)
        Out = []

        for i in range(26):
            letter = words[i][0]
            for j in range(words[i][1]):
                Out.insert(self.findchongfu(Out,letter),letter)

        if self.find(Out):
            return ''
        return ''.join(i for i in Out)

    def findchongfu(self,word,letter):
        for i in range(len(word)-1):
            if word[i] == word[i+1]:
                return i+1
        for i in range(len(word)-1):
            if word[i] != letter and word[i+1] != letter:
                return i+1
        return len(word)
    
    def find(self,word):
        for i in range(len(word)-1):
            if word[i] == word[i+1]:
                return True
        return False
```