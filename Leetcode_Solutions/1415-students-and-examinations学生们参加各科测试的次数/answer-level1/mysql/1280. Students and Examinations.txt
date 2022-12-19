### 解题思路
本题思路：
首先难点在于，有些学生什么考试都没有参加，或者他们只参加了几个考试而不是全部。
我们想在结果那里将所有的学生以及考试一一对应显示出来，如果没有参加考试，就对应考试次数为0.

1. 所以首先，我们需要将student 和 subjects 使用 cross join 连接。生成的表格结果将所有的学生以及考试一一对应显示出来。
2. 其次，再和 Examinations 表格使用left join 连接起来，因为我们不想让没参加考试的学生信息丢失，并且限制条件 id，课程名字都相等。
3. 这时候生成了一个表格，如果参加了考试，则右边的表格就会记录信息，如果没参加，则会以null来显示。
4. 最后select 自己想要的结果，并且group by 和 order by 学生id和课程名字。

### 代码

```mysql
# Write your MySQL query statement below

SELECT s.student_id, s.student_name, sj.subject_name, COUNT(e.subject_name) AS attended_exams
FROM Students s 
CROSS JOIN Subjects sj
	  LEFT JOIN Examinations e
      ON s.student_id = e.student_id AND sj.subject_name = e.subject_name
GROUP BY s.student_id, sj.subject_name
ORDER BY s.student_id, sj.subject_name
```