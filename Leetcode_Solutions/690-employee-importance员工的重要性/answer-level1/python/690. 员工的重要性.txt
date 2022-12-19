### 解题思路
类似于二叉搜索树的搜索，先找到与员工id 对应的根节点，然后寻找子节点

### 代码

```python
# Employee info
class Employee(object):
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates

class Solution(object):
    def getImportance(self, employees, id):
        def addsum(employees,id):
            for e in employees:
                cur = 0
                #找到被调查的员工
                if e.id == id:
                    rns = Employee(e.id,e.importance,e.subordinates)
                    #更新重要值
                    cur = rns.importance
                    break
            #对每一个下属员工重复上述过程
            while rns.subordinates:
                s = rns.subordinates.pop(0)
                #重要值不断更新
                cur += addsum(employees,s)
            return cur
        return addsum(employees,id)

```