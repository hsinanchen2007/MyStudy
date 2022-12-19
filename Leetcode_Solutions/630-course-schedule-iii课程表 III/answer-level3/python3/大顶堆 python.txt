参考的花花酱的思路 https://zxi.mytechroad.com/blog/?s=630
算法步骤
（1）按照结束时间对课程进行排序
（2）使用一个大顶堆来储存已经选择的课程的长度
（3）一旦发现安排了当前课程之后，其结束时间超过了最晚结束时间，那么就从已经安排的课程中，取消掉一门最耗时的课程
```python
import heapq
class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses = sorted(courses,key=lambda l:l[1])
        q = []
        d = 0
        for c in courses:
            if d + c[0] <= c[1]:
                d += c[0]
                heapq.heappush(q,-c[0])
            elif q and -q[0] > c[0]:
                d += c[0] + heapq.heappop(q)
                heapq.heappush(q,-c[0])
        return len(q)
```