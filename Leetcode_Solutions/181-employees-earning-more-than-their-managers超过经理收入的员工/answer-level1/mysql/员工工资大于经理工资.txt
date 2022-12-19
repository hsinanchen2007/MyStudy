### 解题思路
我这种写法，可能效率不高，但思路清晰

### 代码

```mysql
# Write your MySQL query statement below
select 
    name as Employee
from 
    Employee as e
where  
    e.salary > (select salary from Employee where id = e.ManagerId)
```