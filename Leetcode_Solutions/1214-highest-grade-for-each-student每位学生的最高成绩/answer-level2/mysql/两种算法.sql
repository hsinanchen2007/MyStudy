### 解题思路
两种算法 第一种就是先获取每个学生的id和最大成绩然后联源数据表
第二种就是 用源数据表直接查 
### 代码

```mysql
# Write your MySQL query statement below


    select a.student_id,min(e.course_id) as course_id,a.grade from (select student_id,max(grade) as grade from  Enrollments group by student_id
) a left join Enrollments e on a.student_id = e.student_id and a.grade = e.grade group by student_id

SELECT student_id,MIN(course_id) course_id,MAX(grade) grade FROM enrollments
WHERE (student_id,grade) IN (SELECT student_id,max(grade) FROM enrollments GROUP BY student_id)
GROUP BY student_id
ORDER BY student_id ;

```