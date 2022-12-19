### 解题思路
此处撰写解题思路

### 代码

```python
"""
# Employee info
class Employee(object):
    def __init__(self, id, importance, subordinates):
    	#################
        :type id: int
        :type importance: int
        :type subordinates: List[int]
        #################
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
class Solution(object):
    def getImportance(self, employees, id):
        """
        :type employees: List[Employee]
        :type id: int
        :rtype: int
        """
        epsDict = {}
        for ep in employees:
            epsDict[ep.id] = ep
        fifo = []
        fifo.append(id)
        rd = 0
        while rd < len(fifo):
            for subId in epsDict[fifo[rd]].subordinates:
                fifo.append(subId)
            rd += 1
        totalImportnce = 0
        for id in fifo:
            totalImportnce += epsDict[id].importance
        return totalImportnce

```