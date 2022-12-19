**1.首先统计student表中存在部门的学生人数进行统计，代码如下：**
select s.dept_id, count(s.dept_id) as student_number
from student s 
group by s.dept_id
**2.然后了用将department 表和 1中 查询得到的表进行LEFT join 连接，本题难点主要是student中不存在的部门学生人数为0，因此可以考虑使用Case when语句将存在于department中而不存在于1.表中的部门学生人数设置0。组合结果如下**
select dd.dept_name, case when dd.dept_id=c.dept_id then c.student_number else 0 end as student_number from department dd 
left join
(select s.dept_id, count(s.dept_id) as student_number
from student s 
group by s.dept_id) c on c.dept_id=dd.dept_id
order by student_number desc, dd.dept_name