### 解题思路
就是找出所有的项目的最有经验的，然后根据项目和最有经验来比就能选出并列的，只要等于最大的就要，这，，怎么优化一下啊，纯粹就是业务逻辑啊，难受

### 代码

```mysql
# Write your MySQL query statement below

select tmp.project_id project_id,e1.employee_id employee_id
from(
select p.project_id project_id,max(e.experience_years) expert
from Project p 
left join Employee e 
on p.employee_id = e.employee_id
group by p.project_id 
) tmp 
left join Project p1 
on tmp.project_id = p1.project_id
left join Employee e1 
on p1.employee_id = e1.employee_id
where tmp.expert = e1.experience_years
order by tmp.project_id,e1.employee_id
```