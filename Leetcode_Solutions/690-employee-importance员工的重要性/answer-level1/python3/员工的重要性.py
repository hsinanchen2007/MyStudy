### 解题思路
我的思路：用字典存储员工数据，键为id，值为员工类；遍历id，相加。
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)



### 代码

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
        sums = 0
        lists = [id]
        dicts = {}
        for employee in employees:
            if employee.id not in dicts:
                dicts[employee.id] = employee
        i = 0
        while i < len(lists):
            if lists[i] in dicts:
                sums += dicts[lists[i]].importance
                lists += dicts[lists[i]].subordinates
                i += 1
        return sums
```