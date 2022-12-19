### 解题思路
方法：用res（List）记录结果；遍历intervals，如果可合并就合并，令mark[i]]=1，下次可不用遍历。

本来以为很简单的题，到最后花了很多时间，总结原因：
1/ 合并情况分类不全
2/ 先开始不排序讨论情况会更复杂一些


### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        
        res = []
        mark = [0 for _ in range(len(intervals))]

        for m in range(len(mark)):
            if mark[m] == 1: continue
            else:
                r_left = intervals[m][0]
                r_right = intervals[m][1]
                for r in range(m+1, len(mark)):
                    if mark[r]: continue
                    if r_left <= intervals[r][0] <= r_right:
                        r_right = intervals[r][1] if intervals[r][1] > r_right else r_right
                        mark[r] = 1
                    '''
                    elif intervals[r][0] < r_left:
                        if intervals[r][1] > r_right:
                            r_left = intervals[r][0]
                            r_right = intervals[r][1]
                            mark[r] = 1
                        elif r_left <= intervals[r][1] <= r_right:
                            r_left = intervals[r][0]
                            mark[r] = 1
                    '''
                mark[m] = 1

            res.append([r_left, r_right])
        return res

```