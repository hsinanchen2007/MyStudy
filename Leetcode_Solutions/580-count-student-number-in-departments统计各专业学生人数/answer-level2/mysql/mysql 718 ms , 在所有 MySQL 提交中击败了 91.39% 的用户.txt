
select a.`dept_name`,count(b.`student_id`) as `student_number` from `department` as a
left join `student` as b on a.`dept_id` = b.`dept_id` group by a.`dept_id` order by `student_number` desc,`dept_name`asc