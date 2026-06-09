select student_id,min(course_id)course_id,grade
from Enrollments
where (student_id,grade) in (select student_id,max(grade) from Enrollments group by student_id)
group by student_id