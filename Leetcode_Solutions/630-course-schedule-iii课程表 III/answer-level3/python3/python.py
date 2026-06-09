首先根据截至日期对课程排序，遍历排好序的课程表，将符合条件的课程加入优先队列
优先队列为课程时间越长的在队尾
程序这么长主要因为我没有用python内置的优先队列数据结构，而是自己用列表模拟的优先队列。
```
class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key = lambda a:a[1])
        res = [courses[0]]
        count = courses[0][0]
        for i in courses[1:]:
            if count + i[0] > i[1]:
                print("1")
                if i[0] < res[-1][0]:
                    print("1.1")
                    count -= res[-1][0]
                    count += i[0]
                    res.pop()
                    if res:
                        if res[0][0] >= i[0]:
                            res.insert(0,i)
                        else:
                            for m in range(len(res)-1,-1,-1):
                                if res[m][0] < i[0]:
                                    res.insert(m+1,i)
                                    break 
                    else:
                        res.append(i)
            else:
                count += i[0]
                if res[-1][0] <= i[0]:
                    res.append(i)
                else:
                    if res[0][0] >= i[0]:
                        res.insert(0,i)
                    else:
                        for m in range(len(res)-1,-1,-1):
                            if res[m][0] < i[0]:
                                res.insert(m+1,i)
                                break                   
        return len(res)
```
