```python
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        here = [i for i,j in enumerate(S) if j == C]
        a = len(S)
        b = len(here)
        dis = []
        for j in range(b):
            if j == 0:
                for i in range(here[0]+1):
                    dis.append(here[0] - i)
            else:
                for i in range(here[j-1]+1,here[j]+1):
                    if i < (here[j-1]+here[j])/2:
                        dis.append(i - here[j-1])
                    else: dis.append(here[j] - i)
        for i in range(here[b-1]+1,a):
            dis.append(i-here[b-1])
        return dis
        