
```
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        circleNum = 0
        checkedFlg = [0] * len(M)
        que = []
        while (0 in checkedFlg):
            circleNum += 1
            newPerson = checkedFlg.index(0)
            que.append(newPerson)
            checkedFlg[newPerson] = 1
            while(que):
                cur = que[0]                
                for i, value in enumerate(M[cur]):
                    if (value == 1) and (checkedFlg[i] == 0):
                        que.append(i)
                        checkedFlg[i] = 1
                que.pop(0)
        return circleNum

```
