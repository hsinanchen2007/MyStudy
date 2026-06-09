* 执行用时 : 48 ms, 在Valid Boomerang的Python3提交中击败了93.07% 的用户
* 内存消耗 : 13.1 MB, 在Valid Boomerang的Python3提交中击败了100.00% 的用户

```
class Solution:
    def isBoomerang(self, points):
        for i in range(2):
            if points[i][0] == points[i+1][0] and points[i][1] == points[i+1][1]:
                return False
        if (points[0][0] - points[1][0] == 0 and points[1][0] - points[2][0] == 0):
            return False
        elif (points[0][0] - points[1][0] == 0 or points[1][0] - points[2][0] == 0):
            return True
        elif (points[0][1] - points[1][1])/(points[0][0] - points[1][0]) == (points[1][1] - points[2][1])/(points[1][0]-points[2][0]):
            return False
        return True
```