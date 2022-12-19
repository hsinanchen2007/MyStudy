### 解题思路

id 不在 现有的课程里
### 代码

```mysql
# Write your MySQL query statement below
select id , name
from students
where id not in  
(select s1.id
	from students s1 , departments d
	where s1.department_id = d.id); 
```