**方法：使用`left join`和`count(字段名)`**   

解法：
- 查询department表中每个专业的学生人数，要求没有学生的专业也需列出，则需要使用外连接（outer join）。这里使用`left join`，department表作为主表（因为要查看每个专业的学生人数）；
- 对各专业分组后，使用count(student_id)计算各组（专业）的学生人数。不使用count(\*)是因为它不会忽略`null`值，计算对应的行数，如果一个专业没有学生，left join会返回主表（department）的对应的值，而student对应字段的值都为null，count(\*)会返回1，但是实际应该为0，而count(字段名)会忽略null值，返回正确的学生人数。    

```mysql
select d.dept_name,
    count(distinct s.student_id) student_number
from department d 
    left join student s on d.dept_id = s.dept_id
group by d.dept_id
order by student_number desc, d.dept_name asc;
```