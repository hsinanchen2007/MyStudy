### 解题思路
第一次写的时候没注意表明Employee,补上select e1.name as Employee

### 代码

```mysql
# Write your MySQL query statement below
select e1.name as Employee
from employee as e1,employee as e2
where e1.managerid = e2.id
    and e1.salary > e2.salary;
```