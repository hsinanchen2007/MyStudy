### 解题思路
思路1相比思路2快很多，不懂为何，希望有朋友能帮忙答疑。

### 代码

```mysql
#  【思路1】
select max(Salary) as SecondHighestSalary 
from Employee 
where Salary != (
    select Salary from Employee order by Salary desc limit 1
)
-- 【思路2】
-- select (
--     select distinct Salary from Employee
--     order by Salary desc
--     limit 1 offset 1
-- ) SecondHighestSalary
```