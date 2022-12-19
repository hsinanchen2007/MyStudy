### 解题思路
d^2 = (x1-y1)*(x1-y1)+(x0+y0)*(x0+y0)  , 求出从任意一点到其他三点的距离,循环重复求出所有,应该只有两个值,多余两个错误和坐标点有相等的错误,两个结果值中,最小的*2 和最大的结果相等(不要开根号,会出现计算错误)

### 代码

```python3
class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        pl = [p1,p2,p3,p4]
        a = []
        list1 = []
        px = []
        for i in pl:
            pl = [p1,p2,p3,p4]
            pl.remove(i)
            for j in pl:
                if j == i:
                    return False
                a = (j[0]-i[0])**2 + (j[1]-i[1])**2  # 此处没有开根号,开根号的结果会造成小数位错误,
                list1.append(a)
        list1 = set(list1)

        if len(list1) == 2 and (min(list1)*2) == max(list1):
            return True
```