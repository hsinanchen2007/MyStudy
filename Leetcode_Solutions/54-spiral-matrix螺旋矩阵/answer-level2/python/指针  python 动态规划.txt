### 解题思路
设立四个指针left、right、TOP、BOT按顺时针顺序每次把最外围数据存储到结果res中,每完成一边的存储便即时更新一个相应的指针，直到所有数据存储完毕（BOT<TOP or right<left）。

![eea688c3ac4221026ebebd75245e22c.jpg](https://pic.leetcode-cn.com/ac3ea2a90248fe3b70011ffbd664d19f49858d6a3cfb8006eb08e67f6502223b-eea688c3ac4221026ebebd75245e22c.jpg)


### 代码

```python
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix or not matrix[0]:
            return []
        TOP=0
        BOT=len(matrix)-1
        left=0
        right=len(matrix[0])-1
        res=[]
        while BOT>=TOP and right>=left:
            for i in range(left,right+1):      # 上边
                res.append(matrix[TOP][i])
            TOP+=1
            for j in range(TOP,BOT+1):   # 右边
                res.append(matrix[j][right])
            right-=1
            if TOP<=BOT and left<=right:   # 不加限定会导致全部数据存储完毕后回头存储重复数据
                for k in range(right,left-1,-1):   # 下边
                    res.append(matrix[BOT][k])
            BOT-=1
            if TOP<=BOT and left<=right:   
                for q in range(BOT,TOP-1,-1):    # 左边
                    res.append(matrix[q][left])
            left+=1
           
        
        return res

```


![c96857e9cf59f90c3d4fd128412ff7f.png](https://pic.leetcode-cn.com/207d67ce172487c6f13982a15e988f63ccc7035bfdec2da796e7f3c876e1ea53-c96857e9cf59f90c3d4fd128412ff7f.png)
