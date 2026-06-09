```
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        if len(coordinates)<3:
            return True
        if coordinates[1][0]-coordinates[0][0]==0:
            for ii in range(2,len(coordinates)):
                if coordinates[ii][0]!=coordinates[0][0]:
                    return False
        slope = (coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0])
        for ii in range(2,len(coordinates)):
            if coordinates[ii][0]==coordinates[0][0]:
                    return False
            if (coordinates[ii][1]-coordinates[0][1])/(coordinates[ii][0]-coordinates[0][0])!=slope:
                return False
        return True
```
![image.png](https://pic.leetcode-cn.com/7930a217a23a787a886fe8f77bf90e310bc25dd156c808b5a8f065d4496e41fd-image.png)
