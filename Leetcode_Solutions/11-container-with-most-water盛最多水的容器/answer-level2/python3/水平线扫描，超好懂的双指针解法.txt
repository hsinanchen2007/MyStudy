### 解题思路
看到很多题解都是为找更长的板左右移动，直观上不好理解。

我的第一想法是找一条水平线从下至上移动，这样能找到**当前高度h**下，**最宽的**底边长。

这样我们比较的每个数值都是**某个h下的面积最大值**。

图解思路如下：
![image.png](https://pic.leetcode-cn.com/e13743421e3cf78ef5df9c1b78c04bb88bcfe07ab789198adf34a0e58ec755d7-image.png)

![image.png](https://pic.leetcode-cn.com/8ece5ce20ff3e24290e190fba18404981c340e38773fd0b1eb0ddeaf562cc5e6-image.png)

![image.png](https://pic.leetcode-cn.com/96c5ad031d6457f591a914fe7d0a7fc8d308d729dbee1ce5dea0cf9d5143f801-image.png)

![image.png](https://pic.leetcode-cn.com/cb836c0b2869b6499ee1da120587725b571a0b79916e188cd148533437504728-image.png)



### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        '''思路：将一条水平线，从下往上滑动，找出此时能闭合的最长横向距离'''
        # 初始化左右指针与最大面积
        left = 0
        right = len(height)-1
        res = 0
        h = 1 # 高度从1开始

        while left < right:
            while height[left] < h and left < right: # 需要一直保证left < right防止索引超出，下同
                left += 1
            while height[right] < h and left < right:
                right -= 1
            # 两个循环完成后，双指针位于：在h高度下，刚好能闭合的最宽距离两端

            h = min(height[left], height[right])  # 优化版h，不用每次+1地扫描，注释掉这句也可以
            res = max(res, (right-left)*h)
            h += 1  # 一层层向上扫描
        
        return res
            
            
```

![image.png](https://pic.leetcode-cn.com/9265aa2b82108455bd261f74c0be5f45e9e46ec1ffb229a6621e44e5edc08c2d-image.png)
