### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select e1.Id, e1.Month,  if(e2.Salary is not null and e3.Salary is not null, e1.Salary+e2.Salary+e3.Salary, if(e2.Salary is not null, e1.Salary+e2.Salary, if(e3.Salary is not null, e1.Salary+e3.Salary, e1.Salary))) as Salary
from Employee e1
left join Employee e2 on (e1.Id = e2.Id and e2.Month = e1.Month-1)
left join Employee e3 on (e1.Id = e3.Id and e3.Month = e1.Month-2)
where (e1.Id, e1.Month) not in (
    select Id, max(Month)
    from Employee
    group by Id 
)
order by e1.Id, e1.Month desc ;
```