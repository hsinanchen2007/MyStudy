### 解题思路
十四为一个循环，这个很重要，不然第一个用例就过不了。
![捕获.PNG](https://pic.leetcode-cn.com/09acb177bbb8e926ee0978280b7c83c30446c8dbc80d540c423923d5c99fda22-%E6%8D%95%E8%8E%B7.PNG)
### 代码      
```
class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        jk=[cells]
        N = N%14
        for m in range(14):
            k=[None]*8
            k[0] = 0
            k[-1] = 0
            for i in range(1,7):
                if (jk[m][i-1] == 0 and jk[m][i+1]  ==0)or (jk[m][i-1] ==1 and jk[m][i+1] == 1):
                    k[i] = 1
                else:
                    k[i] = 0
            jk.append(k)
        if N !=0:
            return jk[N]
        else:
            return jk[14]
```
