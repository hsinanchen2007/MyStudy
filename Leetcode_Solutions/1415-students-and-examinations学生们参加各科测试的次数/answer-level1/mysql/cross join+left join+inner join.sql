select a.student_id,a.student_name,b.subject_name,
if(e.student_id is null,0,e.times) as attended_exams
from students a
join subjects b
left join
(select c.student_id,c.subject_name,count(d.student_id) as times from 
(select distinct student_id,subject_name from examinations) as c inner join examinations d on
c.student_id=d.student_id and c.subject_name=d.subject_name
group by c.student_id,c.subject_name) as e
on a.student_id=e.student_id and b.subject_name=e.subject_name
order by a.student_id,b.subject_name;