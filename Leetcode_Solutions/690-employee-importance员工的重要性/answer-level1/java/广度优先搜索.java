### 解题思路
此处撰写解题思路

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
        int val=0;
        //map存储所有员工信息
        Map<Integer,Employee> map=new HashMap<>();
        for(Employee emp:employees){
            map.put(emp.id,emp);
        }
        
        Queue<Employee> queue=new LinkedList<>();
        queue.offer(map.get(id));
        while(!queue.isEmpty()){//类似葡萄串
            Employee tmp=queue.poll();
            val+=tmp.importance;
            for(int subId:tmp.subordinates){
                    queue.offer(map.get(subId));    
            }
        }
        return val;
    }
}
```