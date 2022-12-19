Python提交中击败100%用户
![微信图片_20190922113225.png](https://pic.leetcode-cn.com/203352fe92c2d3bf052f5f611e72e21d2893caef5ab6dc0b431b837e86a8defd-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190922113225.png)
解法思路：
1. 用曼哈顿距离作为字典的keys；
2. 遍历矩阵所有点，将各点到(r0,c0)的距离为key，存入字典
3. 将字典输出
```
class Solution(object):
    def allCellsDistOrder(self, R, C, r0, c0):
        maxrow=abs(R-r0-1) if abs(R-r0-1)>abs(r0) else abs(r0)
        maxcol=abs(C-c0-1) if abs(C-c0-1)>abs(c0) else abs(c0)
        distDict = {}
        for dist in range(maxrow+maxcol+1):
            distDict[dist]=[]

        for row in range(R):
            for col in range(C):
                distDict[abs(r0 - row) + abs(c0 - col)].append([row, col])
        result=[]
        for key in distDict.keys():
            for coordinate in distDict[key]:
                result.append(coordinate)
        return result
```
