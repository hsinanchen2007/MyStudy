最好想的穷举暴力解法：
```python
class Solution:
    def trap(self, height: List[int]) -> int:
        sum = 0
        for i in range(len(height)):
            maxleft = 0
            maxright = 0
            for j in range(i, -1, -1):
                maxleft = max(height[j], maxleft)
            for j in range(i, len(height)):
                maxright = max(height[j], maxright)
            sum = min(maxleft, maxright) - height[i] + sum
        return sum
```
结果：超出时间限制，最后一个case出了问题，仔细一看……（靓仔语塞），那么多元素的一个列表……
两个遍历当前元素左面和右面最大值的循环是否能用切片解决，切片的原理没有找到，这里求大神解答
```python
class Solution:
    def trap(self, height: List[int]) -> int:
        sum = 0
        for i in range(len(height)):
            maxleft = 0
            maxright = 0
            maxleft = max(height[0:i+1])
            maxright = max(height[i:len(height)])
            sum = min(maxleft, maxright) - height[i] + sum
        return sum
```
结果：通过
执行用时 :1880 ms, 在所有 Python3 提交中击败了5.01%的用户
内存消耗 :14 MB, 在所有 Python3 提交中击败了5.42%的用户

可能没有比我这更慢的了

