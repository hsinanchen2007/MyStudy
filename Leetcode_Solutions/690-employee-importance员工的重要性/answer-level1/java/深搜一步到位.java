### 解题思路
直接找到当前Id,深搜就行了
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
        int ans = 0;
        for (Employee e : employees) {
            if (e.id == id) {
                ans += e.importance;
                for (int cnt : e.subordinates) {
                    ans += getImportance(employees, cnt);
                }
            }
        }
        return ans;
    }
}
```