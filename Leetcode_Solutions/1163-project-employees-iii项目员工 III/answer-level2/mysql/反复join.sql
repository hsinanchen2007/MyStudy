### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select lhs.project_id, lhs.employee_id
from
(select project_id, P1.employee_id, experience_years
from
Project as P1
join
Employee as E1
on P1.employee_id = E1.employee_id) as lhs
join
(select project_id, max(experience_years) as max_years
from
Project as P1
join
Employee as E1
on P1.employee_id = E1.employee_id
group by project_id) as rhs
on
lhs.project_id = rhs.project_id
where experience_years = max_years
```