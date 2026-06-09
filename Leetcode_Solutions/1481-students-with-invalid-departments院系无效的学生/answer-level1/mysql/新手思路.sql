### 解题思路
简单粗暴

### 代码

```mysql
# Write your MySQL query statement below
select students.id,students.name 
from students left join departments
on students.department_id = departments.id 
where departments.id is null
order by students.id;
```