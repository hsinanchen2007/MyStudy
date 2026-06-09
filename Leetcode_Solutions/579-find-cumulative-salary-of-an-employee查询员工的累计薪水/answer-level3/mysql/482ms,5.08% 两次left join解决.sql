### 解题思路
虽然慢，但是还是记录下

### 代码

```mysql
# Write your MySQL query statement below


select p.id,p.month,(ifnull(p1.salary,0)+lag1salary+ifnull(p.salary,0)) as Salary
from 
    (select t.id ,t.month,t.salary ,t1.month as lag1month,ifnull(t1.salary,0) as lag1salary
    from Employee t
    left join Employee t1
    on t.id = t1.id and t.month = t1.month+1
    ) p
left join Employee p1
on p.id = p1.id and p.month = p1.month+2 
where (p.id,p.month) not in  (select id,max(month)  from Employee group by id)

order by id,month desc

```