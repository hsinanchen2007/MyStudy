### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select case when ct=2 then Salary else null end as SecondHighestSalary
from
(select Salary,ct
from
  (select Salary
    from 
    (select Salary from Employee group by Salary order by Salary desc limit 2) t1) t3
join
    (select count(*) as ct
    from 
    (select Salary from Employee group by Salary order by Salary desc limit 2) t2) t4
) t5 order by Salary limit 1



```