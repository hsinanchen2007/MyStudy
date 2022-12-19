### 解题思路
minn这个有点迷，不懂什么意思
### 代码

```python3
class Solution:
    def computeSimilarities(self, docs: List[List[int]]) -> List[str]:
        
        res = []
        minn = 1e-9   #  精度问题，这个数很重要，具体还不清楚
        docTemp = []
        for i in range(0,len(docs)):
            docTemp.append(set(docs[i]))

        for i in range(0,len(docTemp)-1):
            s1 = docTemp[i]
            for j in range(i+1,len(docTemp)):
                s2 = docTemp[j]
                if len(s1 & s2) == 0:
                    continue
                sim = len(s1 & s2) / len(s1 | s2) + minn
                res.append("{0:d},{1:d}: {2:.4f}".format(i, j, sim))
        return res;
```