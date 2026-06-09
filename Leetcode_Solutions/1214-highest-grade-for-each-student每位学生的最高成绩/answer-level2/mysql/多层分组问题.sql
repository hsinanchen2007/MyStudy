### 解题思路
找分数同样最大的的科目中字典排序较小的一科即对学生和最大成绩进行分组

### 代码

```mysql
# Write your MySQL query statement below
select student_id,min(course_id) course_id,grade 
from Enrollments
where (student_id,grade) in (
select student_id, max(grade) from Enrollments
group by student_id
)
group by student_id,grade
order by student_id;
```