```
# Write your MySQL query statement below
select project_id,employee_id 
from Project x
where employee_id in (
    select employee_id 
    from Employee  where
 experience_years >=all  
 (select experience_years from Employee where employee_id in 
 (select employee_id from Project y where y.project_id = x.project_id)
 )
)
```
只用了select from....还有个all 
目前执行800ms左右
如果all那边改成max 会变成2000ms... 
