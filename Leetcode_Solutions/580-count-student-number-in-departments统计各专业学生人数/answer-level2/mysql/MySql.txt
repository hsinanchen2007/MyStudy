select dept_name,(case when student_num is null then 0 else student_num end) student_number

from

(select dept_id,count(*) student_num

from student 

group by dept_id) t1

right join department t2

on t1.dept_id=t2.dept_id

order by student_number desc,dept_name asc