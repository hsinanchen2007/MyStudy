根据大佬的思路[powcai题解](https://leetcode-cn.com/problems/merge-intervals/solution/pai-xu-by-powcai/)整理了一下：
(1)先按照左边界排升序，
(2)在将相同左边界的元素又按照右边界排一次升序。

大佬就是大佬！！！

我们来看一看强在哪里，这一句：

`res = sorted(intervals)`

可以直接替换下面这一大段代码：

```
        sort_tmp = sorted(intervals, key=lambda inter: inter[0])
        res = []
        i = 0
        while i < len(sort_tmp):
            group = []
            left = sort_tmp[i][0]
            group.append(sort_tmp[i])
            i += 1
            while i < len(sort_tmp) and sort_tmp[i][0] == left:
                group.append(sort_tmp[i])
                i += 1  
            group =  sorted(group, key=lambda g: g[1])   
            res.extend(group)
```

最终答案：
```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sort_tmp = sorted(intervals, key=lambda inter: inter[0])
        res = []
        i = 0
        while i < len(sort_tmp):
            group = []
            left = sort_tmp[i][0]
            group.append(sort_tmp[i])
            i += 1
            while i < len(sort_tmp) and sort_tmp[i][0] == left:
                group.append(sort_tmp[i])
                i += 1  
            group =  sorted(group, key=lambda g: g[1])   
            res.extend(group)
        print(res)

        sort_res = res
        # print(sort_res)
        n = len(sort_res)
        final_res = []
        i = 0
        while i < n:
            left = sort_res[i][0]
            right = sort_res[i][1]
            while i < n-1 and sort_res[i+1][0] <= right:
                right = max(right, sort_res[i+1][1]) 
                i += 1
            final_res.append([left, right])
            i += 1
        return final_res
```
