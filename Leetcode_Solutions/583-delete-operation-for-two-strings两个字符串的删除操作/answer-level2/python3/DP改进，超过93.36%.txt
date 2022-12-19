### 解题思路
DP基础上，把0位置的值提前计算，减少if语句，加速算法。

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        
        if len(word1) == 0 or len(word2) == 0:
            return(max(len(word1),len(word2)))

        l = [[0 for j in range(len(word2))] for i in range(len(word1))]
        
        if word1[0] in word2:
            l[0][word2.index(word1[0]):] = [1 for i in l[0][word2.index(word1[0]):]]
        if word2[0] in word1:
            for i in range(word1.index(word2[0]),len(word1)):
                l[i][0] = 1

        for i in range(1,len(word1)):
            for j in range(1,len(word2)):
                if word1[i] == word2[j]:
                    l[i][j] = l[i-1][j-1] + 1
                else:
                    l[i][j] = max(l[i][j-1],l[i-1][j])

        return(len(word1)+len(word2)-2*l[-1][-1])

```