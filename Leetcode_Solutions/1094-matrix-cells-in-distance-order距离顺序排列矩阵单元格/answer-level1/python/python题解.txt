![image.png](https://pic.leetcode-cn.com/07dd0556eedbbf75bb51dcff5eb4427ca18464c1191c29a28668fae653c58919-image.png)

### 解题思路
首先定义一个数组result存每个距离的坐标，距离为0时将下标存在result[0]中，便利整个数组存下所有下标
将全部下标按顺序取出来即可

### 代码

```python
class Solution(object):
    def allCellsDistOrder(self, R, C, r0, c0):
        """
        :type R: int
        :type C: int
        :type r0: int
        :type c0: int
        :rtype: List[List[int]]
        """
        result = [[] for _ in range(R+C-1)]
        if R == 0 or C == 0:
            return []
        if R == 1 and C==1:
            return [0,0]
        for j in range(R):
            for i in range(C):
                temp = abs(j-r0) + abs(i-c0)
                result[temp].append([j,i])
        
        result1 = []
        for k in result:
            if k:
                for j in k:
                    result1.append(j)
        
        return result1




        


        
```