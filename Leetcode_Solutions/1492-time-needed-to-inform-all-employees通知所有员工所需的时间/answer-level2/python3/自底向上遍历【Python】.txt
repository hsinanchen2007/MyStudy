### 思路

**自底向上遍历**

```
自底向上，每次加上该层员工所需的通知时间，再逐层到上一层负责人。
```

##### Python3代码

```python
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        res = 0
        for i in range(len(manager)):
            # 剪枝
            if informTime[i] == 0:
                temp = 0
                index = i
                # 自底向上遍历
                while index != -1:
                    temp += informTime[index]
                    index = manager[index]
                res = max(res, temp)
        return res
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/1376-Time-Needed-to-Inform-All-Employees/1376.py)