时间o(mn)，空间o(min(m,n))了解下
```matlab
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if len(word1) == 0:
            return len(word2)
        if len(word2) == 0:
            return len(word1)
        array = [[0]*len(word1) for i in range(2)]
        flag = 1
        for i in range(len(word2)):
            flag = 1-flag
            for j in range(len(word1)):
                if i > 0 and j > 0:
                    if word1[j] == word2[i]:
                        t1 = array[1-flag][j-1]
                    else:
                        t1 = array[1-flag][j-1]+1
                    array[flag][j] = min(array[1-flag][j]+1, array[flag][j-1]+1, t1)
                elif i > 0 and j == 0:
                    if word1[j] == word2[i]:
                        array[flag][j] = min(array[1-flag][j]+1, i)
                    else:
                        array[flag][j] = array[1-flag][j]+1
                elif j > 0 and i == 0:
                    if word1[j] == word2[i]:
                        array[flag][j] = min(array[flag][j-1]+1, j)
                    else:
                        array[flag][j] = array[flag][j-1]+1
                else:
                    if word1[j] == word2[i]:
                        array[flag][j] = 0
                    else:
                        array[flag][j] = 1
        return array[flag][-1]
```