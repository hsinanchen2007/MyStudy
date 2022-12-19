### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        result = []
        if len(intervals)==0:
            return result
        sorted_intervals = sorted(intervals, key=lambda d:d[0])
        curr_list = sorted_intervals[0]
        is_merge = False
        for next_list in  sorted_intervals[1:]:
            if  curr_list[-1]  >=next_list[0]  :
                if curr_list[-1]>=next_list[-1] :
                    curr_list = [curr_list[0], curr_list[-1]]
                elif curr_list[-1]<next_list[-1] :
                    curr_list = [curr_list[0], next_list[-1]]

            else:
                result.append(curr_list)
                curr_list = next_list
        result.append(curr_list)

        return result
```

首先对list进行排序，curr_list 和 next_list 查看是否需要合并， 如果合并，将合并后的元素赋值给 curr_list，否则说明当前元素无法被合并，则将当前元素加入到结果集，并令curr_list=nex_list
合并的时候有2种情况
1、如果next_list全部重叠于curr_list中，则直接next_list=curr_list
2、如果next_list和curr_list部分重叠，则  curr_list=[ curr_list的最左，next_list的最右]
