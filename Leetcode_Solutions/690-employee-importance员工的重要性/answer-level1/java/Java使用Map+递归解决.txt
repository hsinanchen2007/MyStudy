### 解题思路
Java先转换**Map**，key为id，value为employee对象；之后利用递归解决问题
***下属的下属也属于自己的下属，这里要注意！***

### 代码

```java
/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/

class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> employeeMap = employees.stream().collect(Collectors.toMap(employee ->
                        employee.id
                , Function.identity()));

        return helper(employeeMap, id);
    }

    private int helper(Map<Integer, Employee> employeeMap, int id) {
        Employee current = employeeMap.get(id);
        if (current == null) {
            return 0;
        }
        int importance = current.importance;
        List<Integer> subordinates = current.subordinates;
        if (subordinates == null || subordinates.size() == 0) {
            return importance;
        }
        for (int subId : subordinates) {
            Employee subEmployee = employeeMap.get(subId);
            if (subEmployee != null) {
                importance += helper(employeeMap, subEmployee.id);
            }
        }
        return importance;
    }
}
```