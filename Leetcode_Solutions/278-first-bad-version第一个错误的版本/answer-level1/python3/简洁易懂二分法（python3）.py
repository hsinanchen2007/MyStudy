**二分法适用范围：**
单调性问题（充分不必要条件，单调问题一定可以用二分法解，但是能用二分法的问题，不一定单调#例如题目：寻找峰值#）
**寻找左右边界**
初始边界：left = 1, right = n, 在此问题中我们每次检测 mid = (left + right) // 2
例子中：1 2 3 4 5 对应 F F F T T

判断 isBadVersion(mid):
True: 更新right = mid
False: 更新left = mid + 1(因为第一个True一定在mid右边))

终止条件：right - left <= 1(相邻或者重合)
```
class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 1, n
        while right - left > 1:

            if isBadVersion((left + right) // 2):
                right = (left + right) // 2
                
            else:
                left = (left + right) // 2 + 1

        if isBadVersion(left):
            return left
        else:
            return right
```
