![image.png](https://pic.leetcode-cn.com/e0b448e75aeb521fef34c65037de332f41b41434a58ff110819ce83479ebad2f-image.png)

```
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        X=[x[0] for x in coordinates]
        if len(set(X))==1:
            return True
        x1,y1,x2,y2=coordinates[0][0],coordinates[0][1],coordinates[1][0],coordinates[1][1]
        if x1==x2:
            return False
        k=(y1-y2)/(x1-x2)
        for i in range(1,len(coordinates)-1):
            x1,y1,x2,y2=coordinates[i][0],coordinates[i][1],coordinates[i+1][0],coordinates[i+1][1]
            if x1==x2:
                return False
            k1=(y1-y2)/(x1-x2)
            if k1!=k:
                return False
        return True
```
