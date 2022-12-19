####  方法一：深度优先搜索DFS
**算法：**
- 让我们使用 `emap = {employee.id -> employee}` 快速查询员工。 
- 现在要找出一个员工的总重要性，它将是该员工的重要性，加上该员工每个下属的总重要性。这是一个简单的深度优先搜索。 

```Python [ ]
class Solution(object):
    def getImportance(self, employees, query_id):
        emap = {e.id: e for e in employees}
        def dfs(eid):
            employee = emap[eid]
            return (employee.importance +
                    sum(dfs(eid) for eid in employee.subordinates))
        return dfs(query_id)
```


```Java [ ]
class Solution {
    Map<Integer, Employee> emap;
    public int getImportance(List<Employee> employees, int queryid) {
        emap = new HashMap();
        for (Employee e: employees) emap.put(e.id, e);
        return dfs(queryid);
    }
    public int dfs(int eid) {
        Employee employee = emap.get(eid);
        int ans = employee.importance;
        for (Integer subid: employee.subordinates)
            ans += dfs(subid);
        return ans;
    }
}
```


**复杂度分析**

* 时间复杂度：$O(N)$。其中 $N$ 是员工人数。我们可以在 `DFS` 中查询每个员工。 
* 空间复杂度：$O(N)$，计算 `DFS` 时隐式调用堆栈的大小。