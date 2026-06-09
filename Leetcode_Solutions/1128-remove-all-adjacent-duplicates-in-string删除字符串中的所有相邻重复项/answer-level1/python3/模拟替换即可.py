```
class Solution:
    def removeDuplicates(self, S: str) -> str:
        if S.__len__()<=1:
            return S
        first=S[0]
        S_list=list(S)
        
        while True:
            tmp=S_list.__len__()
            for i in range(S_list.__len__()):
                try:
                    if S_list[i]==S_list[i+1]:
                        S_list.pop(i)
                        S_list.pop(i)
                except:
                    continue
            if tmp==S_list.__len__():
                break
            else:
                tmp=S_list.__len__()
        return ''.join(S_list)
```
