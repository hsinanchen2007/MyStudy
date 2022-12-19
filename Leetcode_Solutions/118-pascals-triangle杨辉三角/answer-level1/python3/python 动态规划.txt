比较简单，最基本的动态规划。
分成两步，第一步，初始化数组。建二维数组，内容都放0。竖着的边和斜着的边放1。
第二步遍历整个二维数组，把0的部分用动态规划方程算出来的结果替换即可。

```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows==0:
            return []
        i=0
        res=[]
        while i<numRows:
            j=0
            res.append([])
            while j<=i:     
                if j==0 or j==i:   #每行的开头和结尾元素放1
                    res[i].append(1)
                else:               #其余放0，作为标记用
                    res[i].append(0)
                j+=1
            i+=1
        
        for m in range(numRows):
            for n in range(len(res[m])):
                if res[m][n]==0:    #标0的需用动态规划算值修改
                    res[m][n]=res[m-1][n-1]+res[m-1][n]
        return res
```
