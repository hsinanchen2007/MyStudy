# 思路：

 闰年口诀： **四年一闰，百年不闰，四百年再闰。**
# 代码实现：

```Python
class Solution(object):
    def numberOfDays(self, Y, M):
        """
        :type Y: int
        :type M: int
        :rtype: int
        """
        
        if  (Y % 100 != 0 and Y % 4 ==0) or (Y % 100 == 0 and Y % 400 == 0) : #是闰年
            return [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31][M - 1]
        else: #不是闰年
            return [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31][M - 1]
```
# 复杂度分析：
时间复杂度： $O(1)$

空间复杂度： $O(1)$