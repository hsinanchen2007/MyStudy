select S1.student_id,S1.student_name,S2.subject_name,count(E.subject_name)attended_exams
from Students S1 
cross join Subjects S2
left join Examinations E
on S1.student_id=E.student_id and S2.subject_name=E.subject_name
group by S1.student_id,S2.subject_name
order by S1.student_id,S2.subject_name