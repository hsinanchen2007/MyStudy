### 解题思路
计算出headID到每一个点的时间，取最大值返回即可
![UC截图20200308234044.png](https://pic.leetcode-cn.com/e035346d10d906cf9ba74c5424b49cbf176350b6c656ad016e0559c788263608-UC%E6%88%AA%E5%9B%BE20200308234044.png)


### 代码

```python3
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        from collections import defaultdict
        d = defaultdict(list)
        for i in range(len(manager)):
            if manager[i] != -1:
                d[manager[i]].append([i,0])
        stack = [[headID,0]]
        time = 0
        while stack:
            cur = stack.pop(0)
            for item in d[cur[0]]:
                item[1] += (cur[1] + informTime[cur[0]])
                time = max(time,item[1])
                stack.append(item)
        return time

```