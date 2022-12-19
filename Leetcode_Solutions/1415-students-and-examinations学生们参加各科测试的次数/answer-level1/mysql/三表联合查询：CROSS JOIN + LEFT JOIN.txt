1.先连结两个表：对表Students和表Subjects求笛卡尔积，得到4*3行的表
```
SELECT *
FROM Students a CROSS JOIN Subjects b
```
2.再连结三个表：对刚刚得到的新表和表Examinations进行左连结（LEFT JOIN）
```
SELECT *
FROM Students a CROSS JOIN Subjects b
    LEFT JOIN Examinations e ON a.student_id = e.student_id AND b.subject_name = e.subject_name
```
3.查询
```
SELECT a.student_id, a.student_name, b.subject_name, COUNT(e.subject_name) AS attended_exams
FROM Students a CROSS JOIN Subjects b
    LEFT JOIN Examinations e ON a.student_id = e.student_id AND b.subject_name = e.subject_name
GROUP BY a.student_id, b.subject_name
ORDER BY a.student_id, b.subject_name
```
这里不能用COUNT(*)，要用COUNT(e.subject_name)，因为e.subject_name中才有NULL

