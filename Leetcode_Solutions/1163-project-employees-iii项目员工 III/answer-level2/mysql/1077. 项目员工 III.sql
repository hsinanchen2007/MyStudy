### 解题思路
此处撰写解题思路
最高工作年限的人可能有多个，因此，需要先求出每个部门的最高年限，然后查找符合最高年限的所有人
### 代码

```mysql
# Write your MySQL query statement below



select p.project_id,p.employee_id
from Project p inner join Employee e 
on p.employee_id = e.employee_id 
where (p.project_id,e.experience_years)
in (
    select a.project_id,max(b.experience_years) from Project a inner join Employee b 
    on a.employee_id = b.employee_id 
    group by a.project_id
)

```