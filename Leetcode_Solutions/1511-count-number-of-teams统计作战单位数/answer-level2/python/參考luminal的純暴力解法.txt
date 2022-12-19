### 解题思路
由於是對3個元素排序

對於任意的數字k,只要比k小的數*比k大的數(升序)
                                            比k大的數*比k小的數(降序)
用乘法原理相乘即可

比如對於數字k,小於k的有i個,大於k個則對於數字k的升序排列就有 i*j
對於降序,就是大於k的i_個,小於k的j_個,降序排列就是i_*j_個

所以只要遍歷數組累加每個k的情況

### 代码

```python3
class Solution:
    def numTeams(self, a: List[int]) -> int:
        n = len(a)
        ans = 0
        for k in range(n):
            lx = ly = 0
            for  i in range(k):
                if  a[i] < a[k]:
                    lx+=1
                if  a[i] >a[k]:
                    ly+=1
            rx = ry = 0
            for j in range(k+1,n):
                if a[j] > a[k]:
                    rx+= 1
                if  a[j] <a[k]:
                    ry +=1
            ans += lx*rx + ly*ry
        return ans


```