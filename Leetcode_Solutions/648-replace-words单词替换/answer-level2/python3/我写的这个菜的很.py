
```python []
class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        wordlist = sentence.split(' ')
        lenlist=[]
        for i in dict:
            lenlist.append(len(i))
        
        Nm = max(lenlist)
            
        for i in range(len(wordlist)):
            tempword = ''
            N = len (wordlist[i])
            for j in range(N):
                if j>Nm:
                    break
                if tempword in dict:
                    wordlist[i] = tempword
                    break
                else:
                    tempword += wordlist[i][j]
                                
        return ' '.join(wordlist)
```
