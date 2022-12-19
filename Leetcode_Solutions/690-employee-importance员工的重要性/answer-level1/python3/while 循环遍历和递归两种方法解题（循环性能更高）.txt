### 解题思路
此处撰写解题思路

### 代码
方法一：递归
```python3
"""
# Employee info
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        employees_dict = {employee.id: employee for employee in employees}

        def sumimportance(employees):
            
            if not employees:
                return 0
            importance = 0
            sub_employee_ids = []
            for employee in employees:
                importance += employee.importance
                sub_employee_ids.extend(employee.subordinates)
            sub_employees = [employees_dict[id] for id in sub_employee_ids]
            return importance + sumimportance(sub_employees)
        return sumimportance([employees_dict[id]])

```
方法二：while循环
```python3
from collections import deque

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        employees_dict = {employee.id: employee for employee in employees}
        que = deque()
        importance = 0
        que.append(employees_dict[id])
        while que:
            employee = que.popleft()
            importance +=  employee.importance
            sub_employee_ids = employee.subordinates
            for sub_id in sub_employee_ids:
                que.append(employees_dict[sub_id])

        return importance

```