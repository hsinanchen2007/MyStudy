### 解题思路
最常见的连接查询，，，，，

### 代码

```mysql
# Write your MySQL query statement below
select e.unique_id,t.name

from Employees t
left join EmployeeUNI e
on t.id=e.id
```