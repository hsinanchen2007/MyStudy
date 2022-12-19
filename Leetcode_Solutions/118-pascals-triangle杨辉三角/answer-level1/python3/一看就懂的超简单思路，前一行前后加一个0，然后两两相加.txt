一看就懂的超简单思路，第一行为[1]，第二行以后都在前一行前后加一个0，然后两两相加
```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows==0:
            return []
        elif numRows==1:
            return [[1]]
        else:
            out=[[1]]
            for r in range(numRows-1):
                line=[0]+out[r]+[0]
                out.append([line[i]+line[i+1] for i in range(len(line)-1)])
            return out
```
