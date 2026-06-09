**方法一**：首先看到这个问题想到的解法是使用队列，先将给定id对应的员工(employees)入队，并加上其重要性，然后将其出队，同时将其下属入队。。。依此操作直到队空。
使用队列实现的代码如下：
```Java
class Solution {
    public int getImportance(List<Employee> employees, int id) {
        if(employees.size()==0) return 0;
        Queue<Integer> q = new LinkedList<>();
        q.offer(id);
        int result = 0;
        while(!(q.size()==0)){
            int tmp = q.poll();
            for(Employee e: employees){
                if(tmp==e.id){
                    result += e.importance;
                    for(int i: e.subordinates){
                        q.add(i);
                    }
                }
            }
        }
        return result;
    }
}
```
**方法二**：DFS递归解法，与上面的思想一直，只不过是递归实现的：
```Java
class Solution {
    private int result;
    public int getImportance(List<Employee> employees, int id) {
        for(Employee e: employees){
            if(e.id==id){
                result += e.importance;
                if(e.subordinates.size()==0) return result;
                for(int i: e.subordinates){
                    getImportance(employees,i);
                }
            }
        }
        return result;        
    }
}
```
**方法三**：对于方法二进行改进，可以使用一个HashMap按照`employees.id:employees`的格式保存Employee以方便使用id查找员工信息：
```Java
class Solution {
    private Map<Integer,Employee> map = new HashMap<>();
    public int getImportance(List<Employee> employees, int id) {
        for(Employee e: employees) map.put(e.id,e);
        System.out.println(map);
        return search(employees,id);
    }
    public int search(List<Employee> employees, int id){
        Employee e = map.get(id);
        int result = e.importance;
        for(int i: e.subordinates){
            result += search(employees,i);
        }
        return result;
    }
}
```
方法三虽然说是改进，但是比方法二更耗时更耗空间。。。