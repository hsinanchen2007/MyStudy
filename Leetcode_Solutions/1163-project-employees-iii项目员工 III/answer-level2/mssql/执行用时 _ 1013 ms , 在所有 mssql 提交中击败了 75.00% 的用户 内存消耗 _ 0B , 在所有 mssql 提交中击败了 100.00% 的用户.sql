### 解题思路
此处撰写解题思路

### 代码

```mssql
/* Write your T-SQL query statement below */
select tt.project_id,tt.employee_id from
(select p.project_id,e.* from Project p
left join Employee e
on p.employee_id = e.employee_id) tt
inner join
(select project_id,experience_years from(select project_id,experience_years,row_number() over(partition by project_id order by experience_years desc) rn from
(select p.project_id,e.* from Project p
left join Employee e
on p.employee_id = e.employee_id) t) tttt
where rn = 1) ttt
on tt.project_id = ttt.project_id and tt.experience_years = ttt.experience_years

```