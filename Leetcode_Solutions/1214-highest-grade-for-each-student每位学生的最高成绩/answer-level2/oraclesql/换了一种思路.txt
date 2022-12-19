```
/* Write your PL/SQL query statement below */
SELECT student_id, course_id, grade
FROM (
	SELECT student_id, grade, course_id AS course_id, row_number() OVER (PARTITION BY student_id ORDER BY grade DESC,course_id) AS rk
	FROM Enrollments) a
WHERE a.rk = 1
ORDER BY a.student_id
```
