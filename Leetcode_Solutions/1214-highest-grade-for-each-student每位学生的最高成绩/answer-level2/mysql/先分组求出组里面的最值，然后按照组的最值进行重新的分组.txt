### 解题思路


### 代码

```mysql
# Write your MySQL query statement below
select
	tmp1.student_id student_id,
	tmp1.course_id course_id,
	tmp1.grade grade
from
	(
		select
			tmp.student_id student_id,
			tmp.grade grade,
			min(e1.course_id) course_id
		from
			(
				select
					e.student_id student_id,
					max(e.grade) grade
				from
					Enrollments e
				group by
					e.student_id
			) tmp
		left join Enrollments e1 on tmp.student_id = e1.student_id
		and e1.grade = tmp.grade
		group by
			tmp.student_id,
			tmp.grade
	) tmp1

```