```mysql
# Write your MySQL query statement below

SELECT a.student_id,a.student_name,a.subject_name,IFNULL(COUNT(b.subject_name),0) AS attended_exams
FROM 
(SELECT student_id, student_name,Subjects.subject_name
FROM Students, Subjects) AS a
LEFT JOIN Examinations AS b
ON b.student_id = a.student_id AND b.subject_name = a.subject_name
GROUP BY a.student_id, a.subject_name
ORDER BY student_id,subject_name
```