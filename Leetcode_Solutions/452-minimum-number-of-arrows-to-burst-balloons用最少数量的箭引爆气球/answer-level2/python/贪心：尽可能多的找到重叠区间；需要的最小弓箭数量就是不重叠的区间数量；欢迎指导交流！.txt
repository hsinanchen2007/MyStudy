```
class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        if not points:
            return 0
        # 升序
        points.sort()
        res=[]
        # 尽可能少的区间数量
        left=points[0][0]
        right=points[0][1]
        for i in range(1,len(points)):
            # print(left,right)
            # 区间重叠
            if right>=points[i][0]:
                # 更新左端
                left=points[i][0]
                # 更新右端
                if right>points[i][1]:
                    right=points[i][1]
            else:
                res.append([left,right])
                left=points[i][0]
                right=points[i][1]
        res.append([left,right])
        # print(res)
        return len(res)

```
![WechatIMG231.png](https://pic.leetcode-cn.com/9d497a544f12bfafdf4872a41dd560c66988285d54085c1ed47fe9651980550e-WechatIMG231.png)
