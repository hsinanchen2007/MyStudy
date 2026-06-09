### 解题思路
此处撰写解题思路
1.先找出每个学生对应的最大的成绩
2.取出拥有最大成绩的的最小课程
### 代码

```mysql
# Write your MySQL query statement below

select a.student_id as student_id,min(a.course_id) as course_id,a.grade as grade
from Enrollments a
where (a.student_id,a.grade)
in (
    select student_id,max(grade) as grade
    from Enrollments 
    group by student_id
)
group by a.student_id

order by a.student_id

```