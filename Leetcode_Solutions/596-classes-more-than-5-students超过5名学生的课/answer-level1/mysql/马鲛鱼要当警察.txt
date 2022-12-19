### 解题思路
此处撰写解题思路
终于过了，发现是没有考虑学生的重复选课
以班级class分组之后去掉重复的学生，大于等于5的课程就是学生选的
### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select class from  courses group by class having count(distinct student)>=5;
```