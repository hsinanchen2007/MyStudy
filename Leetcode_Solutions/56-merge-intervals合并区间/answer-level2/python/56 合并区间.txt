### 解题思路
list.sort(cmp=None, key=None, reverse=False) 排序。
reverse -- 排序规则，reverse = True 降序， reverse = False 升序（默认）。


### 代码

```python
class Solution(object):
    def mergetwo(self, list1, list2):
        if list2[0] <= list1[1]:
            left = min(list1[0], list2[0])
            right = max(list1[1], list2[1])
            return [left, right]

    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """

        intervals.sort() 
        res = []
        if len(intervals)==1: return intervals
        # print intervals

        tmp_list = []
        for i in range(1,len(intervals)):
            print i, intervals[i]
            if not tmp_list:
                tmp_list = intervals[i-1]
                
            if intervals[i][0] <= tmp_list[1]:
                tmp_list = self.mergetwo(tmp_list,intervals[i])
                # print 'step1', tmp_list
                if i == len(intervals)-1:
                    res.append(tmp_list)
            else:
                # print 'step2', tmp_list
                if not tmp_list:
                    res.append(intervals[i-1])
                else:
                    res.append(tmp_list)
                    tmp_list = []
                if i == len(intervals)-1:
                    res.append(intervals[i])
                

        return res


```



### 解题思路
官方答案：https://leetcode-cn.com/problems/merge-intervals/solution/he-bing-qu-jian-by-leetcode/


### 代码

```python
class Solution:
    def merge(self, intervals):
        intervals.sort(key=lambda x: x.start)

        merged = []
        for interval in intervals:
            # if the list of merged intervals is empty or if the current
            # interval does not overlap with the previous, simply append it.
            if not merged or merged[-1].end < interval.start:
                merged.append(interval)
            else:
            # otherwise, there is overlap, so we merge the current and previous
            # intervals.
                merged[-1].end = max(merged[-1].end, interval.end)

        return merged

```