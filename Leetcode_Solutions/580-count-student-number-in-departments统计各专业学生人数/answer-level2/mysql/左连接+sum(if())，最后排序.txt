### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below


select d.dept_name,sum(if (s.student_id is null,0,1)) as student_number 
from department d left join student s
on d.dept_id = s.dept_id
group by d.dept_id
order by student_number desc,d.dept_name asc


```