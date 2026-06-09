### 解题思路
临时表 算出 team size，然后再连接employee表

### 代码

```mysql
# Write your MySQL query statement below
select e.employee_id, t.team_size
from employee e
join
(select team_id, count(team_id) as team_size
from employee
group by team_id) t
on e.team_id = t. team_id
```