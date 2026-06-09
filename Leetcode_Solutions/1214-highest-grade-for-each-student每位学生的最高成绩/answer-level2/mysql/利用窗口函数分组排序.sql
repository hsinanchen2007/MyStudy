```
SELECT student_id, MIN(t.course_id) as course_id, grade
FROM
(SELECT student_id, course_id, grade,
       RANK() OVER (PARTITION BY student_id 
                    ORDER BY grade DESC) as ranking
FROM enrollments) AS t
WHERE ranking = 1
GROUP BY student_id,grade
```
注意：mysql8.0以上版本才支持窗口函数