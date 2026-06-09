1. 双指针
本质是求矩阵的面积 长度 * 宽度 = (j - i) * min(j, i)
没有考虑到一点是: 为什么双指针是最优解? 这个同学解释很到位

https://leetcode-cn.com/problems/container-with-most-water/solution/zhi-guan-de-shuang-zhi-zhen-fa-jie-shi-by-na-kong/ 
```
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i, j, _max = 0, len(height) - 1, 0
        while(i < j):
          d_i, d_j = height[i], height[j]
          # _max = max(_max, min(d_i, d_j) * (j - i))
          if d_i > d_j:
              _max = max(_max, d_j * (j - i))
              j -= 1
          else:
              _max = max(_max, d_i * (j - i))
              i += 1
        return _max
```

2. 暴力
但是超时了
```
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        # double pointer
        _max = 0
        for i in range(0, len(height) - 1):
            for j in range(i + 1, len(height)):
                _max = max(_max, min(height[i], height[j]) * (j - i))
        return _max
```
