### 解题思路
拓扑排序在这里的应用可以理解为：如果B是A的先修课程，那么B就会排列在A后面。我们用`degrees`来记录这个排序：如果A课程的degree是0，代表A课程没有先修课程或者所有A的先修课程都已经修完了。

整体的思路就是：我们先算出所有课的degree（需要几门先修课），然后把degree为0的课程全部上完。如果我们上完的课刚好是其他课程的先修课，那么我们就在相应课程的degree上面减去相应的数量，然后继续上degree为0的课。如此循环直至没有degree为0的课。

最后，怎么判断是否全部课程都已经上完呢？我用一个`counter`变量来记录我们已经上过的课程数量。对比`counter`和`numCourses`就有结果了。

### 代码

```python3
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Topological sorting
        # pre stores all prerequisites for its key
        # degrees stores degree for every course 
        # (i.e. # of prerequisites the course has)
        pre = dict()
        degrees = [0] * numCourses
        for course, prerequisite in prerequisites:
            if course in pre:
                pre[course].append(prerequisite)
            else:
                pre[course] = [prerequisite]
            degrees[prerequisite] += 1
            
        # stack stores all courses with degree 0 
        # (i.e. no prerequisites required, or all prerequisites are met)
        stack = []
        for i in range(numCourses):
            if degrees[i] == 0:
                stack.append(i)
        counter = 0
        
        # remove course with degree 0 until no more 0 degree courses left
        while stack:
            course = stack.pop()
            counter += 1
            if course not in pre:
                continue
            for prerequisite in pre[course]:
                degrees[prerequisite] -= 1
                if degrees[prerequisite] == 0:
                    stack.append(prerequisite)
        # all courses are visited -> 
        # there is no acyclic in this graph -> 
        # one can take all courses
        return counter == numCourses
```