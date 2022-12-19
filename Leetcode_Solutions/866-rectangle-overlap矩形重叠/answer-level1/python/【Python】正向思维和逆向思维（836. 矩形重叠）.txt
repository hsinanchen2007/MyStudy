# 正向思维



## 思路

这种题目，我们应该考虑到可以直接正向解决，即分析下重叠的有多少种，然后分别考虑。

参考 https://leetcode.com/problems/rectangle-overlap/discuss/133175/C%2B%2B-Solution-with-easy-explanation

第一种情况: Rec2 intersects with Rec1 on top right corner

               ____________________x4,y4
              |                   |
       _______|______x2,y2        |
      |       |______|____________|
      |      x3,y3   |
      |______________|
     x1,y1
              
第二种情况: Rec2 intersects with Rec1 on top left corner

       ___________________  x4,y4
      |                   |
      |            _______|____________x2,y2
      |___________|_______|           |
    x3,y3         |                   | 
                  |___________________|
                x1,y1

第三种情况: Rec2 intersects with Rec1 on bottom left corner
     
               ____________________x2,y2
              |                   |
       _______|______x4,y4        |
      |       |______|____________|
      |      x1,y1   |
      |______________|
     x3,y3
              
 第四种情况: Rec2 intersects with Rec1 on bottom right corner
     
       ___________________  x2,y2
      |                   |
      |            _______|____________x4,y4
      |___________|_______|           |
    x1,y1         |                   | 
                  |___________________|
                x3,y3
    
    bool case1 = (x1 < x4 && x3 < x2 && y1 < y4 && y3 < y2); //top right intersection
    bool case2 = (x3 < x2 && x1 < x4 && y1 < y4 && y3 < y2); //top left intersection
    bool case3 = (x3 < x2 && x1 < x4 && y3 < y2 && y4 < y1); //bottom left intersection
    bool case4 = (x1 < x4 && x3 < x2 && y3 < y2 && y4 < y1); //bottom right intersection
    

观察式子，发现这四种情况判断是一样的。

## 代码

```python
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1, y1, x2, y2, x3, y3, x4, y4 = rec1[0], rec1[1],  rec1[
            2], rec1[3], rec2[0],  rec2[1],  rec2[2], rec2[3]
        return x1 < x4 and x3 < x2 and y1 < y4 and y3 < y2
```

**复杂度分析**
- 时间复杂度：$O(1)$
- 空间复杂度：$O(1)$
# 逆向思维



## 思路

我们也可以采用逆向思维， 考虑不重叠的情况，剩下的就是重叠的情况。

第一种情况: 

                          ____________________x4,y4
                          |                  |
       _____________x2,y2 |                  |
      |              |    |__________________|
      |      x3,y3   |
      |______________|
     x1,y1
              
第二种情况: Rec2 intersects with Rec1 on top left corner

       ___________________  x4,y4
      |                  |
      |                  |      
      |__________________|           
    x3,y3         ___________________x2,y2
                  |                   |
                  |                   | 
                  |___________________|
                x1,y1


...

## 代码

```python
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if rec1[2] <= rec2[0] or rec2[2] <= rec1[0]: return False
        if rec1[3] <= rec2[1] or rec2[3] <= rec1[1]: return False
        return True
```
**复杂度分析**
- 时间复杂度：$O(1)$
- 空间复杂度：$O(1)$

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)