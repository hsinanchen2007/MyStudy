### 解题思路
这种题目就是要拆解。
1、求出每个部门的最高工作经验年数，部门ID,及年数组成的组合作为下一个query的过滤条件
2、将2表连接，然后用 IN 子语句 选出符合部门ID及年数条件的所有组合。
3、最外侧的SELECT语句选择符合题目要求的column即可。
这里比较关键的是IN的用法，表示要同时满足。

### 代码

```mysql
# Write your MySQL query statement below
select p.project_id,e.employee_id
from Project p 
inner join Employee e 
on p.employee_id  = e.employee_id 
where (p.project_id,e.experience_years) in
(select p.project_id,max(e.experience_years) as max_ex_yr
from Project p 
inner join Employee e 
on p.employee_id  = e.employee_id 
group by p.project_id)
```