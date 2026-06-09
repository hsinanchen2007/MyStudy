### 解题思路
1.对于本题中的数据，先建立两个HashMap,分别储存id->employee键值对和id->isVisited键值对（用于标记是否访问过）
2.以参数id为入口，开始BFS
3.对于每一个搜索到的员工，做以下操作：
    - 标记为已访问
    - result加上员工本身的importance
    - 遍历他的属下，若没访问过，则bfs搜索该员工,result加上返回值
    - 返回result
4.调用bfs(id)
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
    private HashMap<Integer,Employee> employeeList;
    private HashMap<Integer,Boolean> isVisisted;
    public int getImportance(List<Employee> employees, int id) {
        employeeList=new HashMap<>();
        isVisisted=new HashMap<>();
        employees.forEach(employee -> {
            employeeList.put(employee.id,employee);
            isVisisted.put(employee.id, false);
        });
        return bfs(id);
    }

    public int bfs(int id){
        isVisisted.replace(id,true);
        Employee employee=employeeList.get(id);
        int result=employee.importance;
        for (Integer subordinate : employee.subordinates) {
            if (!isVisisted.get(subordinate)){
               result+=bfs(subordinate);
            }
        }
        return result;
    }
}
```