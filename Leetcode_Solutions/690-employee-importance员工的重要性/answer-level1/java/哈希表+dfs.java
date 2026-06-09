```java
class Solution {
    Map<Integer, Employee> map;
    public int getImportance(List<Employee> employees, int id) {
        map = new HashMap<>(employees.size());
        for (Employee employee : employees) {
            map.put(employee.id, employee);
        }
        return dfs(map.get(id));
    }

    private int dfs(Employee employee) {
        if (employee == null) {
            return 0;
        }
        int importance = employee.importance;
        for (Integer subId : employee.subordinates) {
            importance += dfs(map.get(subId));
        }
        return importance;
    }
}
```
