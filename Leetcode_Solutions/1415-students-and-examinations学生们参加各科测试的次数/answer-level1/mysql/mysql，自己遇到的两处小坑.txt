### 解题思路
其实题目比较简单，自己在做的时候遇到两个小坑
第一个是关于临时生成的虚表，也就是
```
(select stu.student_id, stu.student_name, sub.subject_name 
from Students as stu
join Subjects as sub) as s
```
这里也会出错，具体原因通过测试用例，我个人的理解是生成的虚表不是实际存在的，直接对它进行 left join 
并不会将笛卡儿积得到的所有结果列出。

第二个是关于group by的参数
```
select stu.student_id, stu.student_name, sub.subject_name, count(e.student_id) as attended_exams 
from Students as stu
join Subjects as sub
left join Examinations as e
on stu.student_id = e.student_id and sub.subject_name = e.subject_name
**group by e.student_id, e.subject_name**
order by stu.student_id, sub.subject_name
```
跟下面正确的代码差别在于加粗，一开始不明白为什么测试用例有无法通过的，后来通过查看测试用例找到原因。
如果测试用例的 Examinations 表不包含某个同学，那我用 group by e.student_id, e.subject_name 就会出错。
### 代码

```mysql
# Write your MySQL query statement below
select stu.student_id, stu.student_name, sub.subject_name, count(e.student_id) as attended_exams 
from Students as stu
join Subjects as sub
left join Examinations as e
on stu.student_id = e.student_id and sub.subject_name = e.subject_name
**group by stu.student_id, sub.subject_name**
order by stu.student_id, sub.subject_name
```
如有错误，请指正，谢谢！