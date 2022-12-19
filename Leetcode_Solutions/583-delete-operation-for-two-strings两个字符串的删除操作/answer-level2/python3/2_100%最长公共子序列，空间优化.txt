![image.png](https://pic.leetcode-cn.com/f581ffb0e6c76804b6d6c2d3ada8ba2b90c392280046a09a74d7e625ce560589-image.png)

时间都是O(mn)这个是优化了空间的，只用O(2n)空间的


```
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        word1,word2=' '+word1,' '+word2
        m,n=len(word1),len(word2)
        d=[[0]*n,[0]*n]
        t=0
        for i in range(1,m):
            for j in range(1,n):
                if word1[i]==word2[j]:
                    d[t][j]=d[1-t][j-1]+1
                else:
                    d[t][j]=max(d[1-t][j],d[t][j-1])
            t=1-t
        return m+n-d[1-t][-1]*2-2
```

![image.png](https://pic.leetcode-cn.com/13ff13be2b31effaed3c6e542d0f7cf4824481c7e38454ae56bd2a4b004c56e9-image.png)


这个是没有优化空间的，空间就是O(mn)了，时间也差不太多。

```
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        word1,word2=' '+word1,' '+word2
        m,n=len(word1),len(word2)
        d=[[0]*n for _ in range(m)]
        for i in range(1,m):
            for j in range(1,n):
                if word1[i]==word2[j]:
                    d[i][j]=d[i-1][j-1]+1
                else:
                    d[i][j]=max(d[i-1][j],d[i][j-1])
        return m+n-d[-1][-1]*2-2
```