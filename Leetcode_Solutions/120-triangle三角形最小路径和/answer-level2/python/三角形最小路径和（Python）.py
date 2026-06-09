这一题我是用了两种方法，回溯法和动态规划法。本以为效果会差不多，却没想到是天差地别。我先讲回溯法吧！

方法一：回溯法
简而言之，就是一步步试探，如果符合要求就继续下一步直至找出结果，反之则退回到上一步，试探其他的情况。

代码如下：
```python
class Solution(object):
    # 本题可使用回溯法解决
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        def back(row, col, min_sum):
            if row >= len(triangle):
                return min_sum
            min_sum += triangle[row][col]
            return min(back(row+1, col, min_sum), back(row+1, col+1, min_sum))
        return back(0, 0, 0)

if __name__ == "__main__":
    triangle = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
    min_sum = Solution().minimumTotal(triangle)
    print(min_sum)
```
但是可气的是，竟然超出时间限制了。
此方法不行，那就只能试试看动态回归方法了。

方法二：动态回归算法
动态回归方法简而言之就是：将整个大问题拆分成一个个小步骤求解，它不需要回溯，因此时间效率会快些。
对于本题而言，采取的是从底向上遍历法。即：从倒数第二行开始依次遍历，最后triangle[0][0]即是我们想要的结果

代码如下：
```python
class Solution(object):
    # 本题可使用动态规划法解决
    # 从倒数第二行开始依次遍历，最后triangle[0][0]即是我们想要的结果
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if len(triangle) == 0:
            return 0
        row = len(triangle) - 2
        for row in range(row, -1, -1):
            for col in range(len(triangle[row])):
                triangle[row][col] += min(triangle[row+1][col],triangle[row+1][col+1])
        return triangle[0][0]
    
if __name__ == "__main__":
    triangle = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
    min_sum = Solution().minimumTotal(triangle)
    print(min_sum)
```
执行效率就是还不错啦，在97%左右。

![image.png](https://pic.leetcode-cn.com/b90fe3b3152b757965f99466bd389d0e1fb16df83847cb4edff72ed05baafc82-image.png)