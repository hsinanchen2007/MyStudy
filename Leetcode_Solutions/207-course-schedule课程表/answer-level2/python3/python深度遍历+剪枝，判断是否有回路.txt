### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if len(prerequisites) == 1:
            return True
        #记录是否有访问过，用于剪枝
        visited = set()
        #pre作为Key,cur作为value，构筑map
        hashmap = {}
        for course in prerequisites:
            if course[0] in hashmap.keys():
                hashmap[course[0]].append(course[1])
            else:
                hashmap[course[0]] = [course[1]]

        def hascircle(course, path):
            #如果访问过，直接返回，做到剪枝
            if course in visited:
                return True
            flag = True
            if course not in hashmap.keys():
                return True

            #DFS的精髓，深度遍历每一个前置课程
            for i in hashmap[course]:
                if i in path:
                    return False
                path_set.add(i)
                flag = hascircle(i, path)
                #容易忽视的地方，如果返回是false，要结束访问
                if not flag:
                    return False
                path_set.remove(i)
            #只有遍历了这个节点所有的前置节点后，才能加到visited里面
            visited.add(course)

            return flag

        #每个课程进行遍历，判断是否有回路
        for i in hashmap.keys():
            path_set = set()
            path_set.add(i)
            if not hascircle(i, path_set):
                return False
        return True
```