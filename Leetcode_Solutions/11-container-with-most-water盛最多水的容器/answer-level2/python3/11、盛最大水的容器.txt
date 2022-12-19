```
"""
时间复杂度为O(n)， 空间复杂度为O(1)
思路：left、right游标分别从列表左右两端向中间靠拢
1、计算以left、right为左右游标的容量（取游标指向的值中较小的作为容器高度）
2、比较left、right两个游标指向值的大小，较小的往下一个位置移动，
否则随便选择一个游标下移，在本程序中固定选择右边的游标下移
3、重复步骤1 的计算，直到程序结束
"""
class Solution:
    def maxArea(self, height: list) -> int:
        max = 0
        left = 0
        right = len(height) - 1
        while left < right:
            l = left  #暂存左边游标的位置
            r = right  #暂存右边游标的位置
            if height[left] < height[right]:
                h = height[left]
                left += 1
            else:
                h = height[right]
                right -= 1
            tmp = h * (r - l)  #计算当前容器的容量
            max = tmp if tmp > max else max
        return max
```
