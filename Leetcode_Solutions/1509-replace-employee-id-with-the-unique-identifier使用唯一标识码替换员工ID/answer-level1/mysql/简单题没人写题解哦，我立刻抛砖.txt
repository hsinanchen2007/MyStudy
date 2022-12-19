### 解题思路


### 代码

```mysql
# Write your MySQL query statement below
select e2.unique_id,e1.name
from employees e1 left join employeeuni e2
on e1.id = e2.id;
```