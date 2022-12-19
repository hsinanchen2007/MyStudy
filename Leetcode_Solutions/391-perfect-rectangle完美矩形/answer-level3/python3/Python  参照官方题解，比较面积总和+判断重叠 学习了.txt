![image.png](https://pic.leetcode-cn.com/5d36adc6dd193b0c870fdf6d9a6462527f4531cdae24f99cbd600850cebe1df2-image.png)


一开始想到了要用面积总和来判断，但是没想到怎么判断重叠，看了下别的题解，用顶点出现次数的奇偶性可以判断重叠，比较Tricky,学习了


```
'''
更新矩形的四个边界，边界形成的矩形面积和所有矩形面积和相等，是完美平铺的
必要条件，同时还需要保证没有重叠，判断有没有重叠的方法比较巧妙，不断将新增矩形的
四个顶点加入集合，如果同一个顶点出现偶数次，就抵消掉，最后剩余的顶点数如果是4个
且就是矩形边界组成的4个顶点，那就没有重叠
'''


from typing import List
class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        bound = [0x7fffffff, -0x7fffffff, 0x7fffffff, -0x7fffffff]
        area_cnt = 0

        pos_set = set()
        for i1, j1, i2, j2 in rectangles:
            bound[0] = min(bound[0], i1, i2)
            bound[1] = max(bound[1], i1, i2)
            bound[2] = min(bound[2], j1, j2)
            bound[3] = max(bound[3], j1, j2)
            area_cnt += abs(i1-i2) * abs(j1-j2)

            for ii, jj in [(i1, j1), (i1, j2), (i2, j1), (i2, j2)]:
                if (ii, jj) in pos_set:
                    pos_set.remove((ii, jj))
                else:
                    pos_set.add((ii, jj))

        # 下面条件检查有没有重叠
        if len(pos_set) != 4:
            return False

        for ii, jj in [(bound[0], bound[2]), (bound[0], bound[3]), (bound[1], bound[2]), (bound[1], bound[3])]:
            if (ii, jj) not in pos_set:
                return False

        # 检查面积总和相等
        return area_cnt == abs(bound[0]-bound[1]) * abs(bound[2]-bound[3])
```
