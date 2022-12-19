```
class Solution:
    def findJudge(self, N, trust):
        tmp = [(i+1) for i in range(N)]
        one = []
        for i in range(len(trust)):
            if trust[i][0] not in one:
                one.append(trust[i][0])
                tmp.remove(trust[i][0])
            else:
                pass
        ans = []
        if len(tmp) != 1:
            return -1
        else:
            for i in range(len(trust)):
                if trust[i][1] == tmp[0]:
                    ans.append(trust[i][0])
                else:
                    pass
            if len(set(ans)) == (N-1):
                return tmp[0]
            else:
                return -1
```
