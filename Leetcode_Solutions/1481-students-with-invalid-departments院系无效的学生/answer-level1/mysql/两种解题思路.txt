### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

#第一种解法
select id,`name` from Students where department_id not in ( select distinct id from Departments) order by id asc

#第二种解法
select s.id,s.`name` from Students s left join Departments d on s.department_id = d.id where d.`name` is null  order by id asc
```