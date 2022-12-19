```java
class Solution {
    public int getImportance(List<Employee> employees, int id) {
        //dump all the employee info into a map which is a helpful look up data structure 
        Map<Integer, Employee> map = new HashMap<>();
        for (Employee employee : employees) {
            map.put(employee.id, employee);
        }

        // building a query queue
        Queue<Integer> employeeIdQueue = new PriorityQueue<>();
        employeeIdQueue.addAll(map.get(id).subordinates);
        
        int currentIdEmployeeImportance = map.get(id).importance;
        if (employeeIdQueue.isEmpty()) {
            return currentIdEmployeeImportance;
        }

        int importanceSum = currentIdEmployeeImportance;
        while (!employeeIdQueue.isEmpty()) {
            Employee employee = map.get(employeeIdQueue.poll());
            importanceSum += employee.importance;
            for (Integer employeeId : employee.subordinates) {
                Employee curEmployee = map.get(employeeId);
                importanceSum += curEmployee.importance;
                employeeIdQueue.addAll(curEmployee.subordinates);
            }
        }

        return importanceSum;
    }
}
```