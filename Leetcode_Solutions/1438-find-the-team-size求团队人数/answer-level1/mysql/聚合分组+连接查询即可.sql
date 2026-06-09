### 解题思路


### 代码

```mysql
# Write your MySQL query statement below

select e.employee_id,s.team_size
from Employee e
left join
(
    select team_id,count(*) team_size 
    from   Employee group by team_id
    ) s
on e.team_id=s.team_id
```