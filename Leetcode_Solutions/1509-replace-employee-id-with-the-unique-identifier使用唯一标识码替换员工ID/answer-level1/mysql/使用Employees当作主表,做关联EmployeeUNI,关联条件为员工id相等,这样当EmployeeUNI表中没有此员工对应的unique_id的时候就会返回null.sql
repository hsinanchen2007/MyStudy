### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select a2.unique_id,a1.name
from Employees a1
left join EmployeeUNI a2
on a1.id=a2.id
```