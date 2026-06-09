### 解题思路
通过ifnull(value , null)  函数， 将空值赋值为null
通过 limit 1 offset 1   获取排序后第二个值

### 代码

```mysql
# Write your MySQL query statement below

select  IFNULL(
    (
select 
distinct(Salary)
from 
Employee
order by 
Salary desc
limit 1 offset 1)
,null) as SecondHighestSalary 
```