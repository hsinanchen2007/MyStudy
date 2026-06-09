### 解题思路
本题采用双指针算法求解。使用暴力法（枚举）提交时出现超时。

以下内容是双指针法与本题的结合点：

向内收窄短板可以获取面积最大值。换个角度理解：
若不指定移动规则，所有移动出现的 S(i, j)的状态数为 C(n, 2)，即暴力枚举出所有状态。
在状态 S(i, j)下向内移动短板至 S(i + 1, j)（假设 h[i] < h[j]），则相当于消去了 {S(i, j - 1), S(i, j - 2), ... , S(i, i + 1)} 状态集合。而所有消去状态的面积一定 <= S(i, j)：
短板高度：相比 S(i, j) 相同或更短（<= h[i]）；
底边宽度：相比 S(i, j)更短。
因此所有消去的状态的面积都 < S(i, j)。通俗的讲，我们每次向内移动短板，所有的消去状态都不会导致丢失面积最大值 。
复杂度分析：

时间复杂度 O(N)，双指针遍历一次底边宽度 N 。
空间复杂度 O(1)O(1)，指针使用常数额外空间。


### 代码

```python
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i,j,area=0,len(height)-1,0
        while i<j:
            if height[i]<height[j]:
                area=max(area,(j-i)*height[i])
                i+=1
            else:
                area=max(area,(j-i)*height[j])
                j-=1
        return area
```
```
