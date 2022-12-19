### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select student_id,course_id, grade from
(SELECT student_id,course_id, grade
    ,if (@id = student_id,0,@num :=1) as num,
    if(@id = student_id,student_id,@id := student_id) as id
FROM
    (select * from enrollments order by student_id,grade desc,course_id)a2,
    (SELECT @id:=0)a,(SELECT @num:=0)aa
)t
where num = 1
order by student_id
```