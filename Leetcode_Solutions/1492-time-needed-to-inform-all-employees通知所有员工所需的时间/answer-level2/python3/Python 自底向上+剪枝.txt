示例输入太特殊，我们看下面这个图的遍历过程。


![5354.png](https://pic.leetcode-cn.com/3fab922f8c68f245e3064f4fba9cee599c3624510236b9d72589b56d9aec228d-5354.png)

其实还可以继续剪，需要加判断条件，可以探讨一下优化。


```python
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        mins = [0] * n
        for i in range(n):
            cur_i, cur_min = i, 0
            # print(cur_i, end=' ')
            while manager[cur_i] != -1:
                cur_i = manager[cur_i]
                # print(cur_i, end=' ')
                cur_min += informTime[cur_i]
            mins[i] = cur_min + mins[cur_i]
            manager[i] = -1
            # print(manager)
            # print('min', cur_min)
        return max(mins)
```