### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select p.*,ifnull(p2.attended_exams,0) as attended_exams from  
(
    select t1.student_id,t1.student_name,t2.subject_name
 from   Students  t1 join Subjects t2 
  ) p left join 
  
(select student_id,count(subject_name) as attended_exams,subject_name
from Examinations group by student_id,subject_name) p2
on p.student_id = p2.student_id and p.subject_name = p2.subject_name
order by student_id,subject_name 
```