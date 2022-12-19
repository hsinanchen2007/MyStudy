### 解题思路
先对薪水去重，因为表中如果只存在一种薪水值也会被判定不存在第二高的薪水。然后用窗口函数生成排序列，将非第二高的薪水转成null。

### 代码

```mssql
/* Write your T-SQL query statement below */
select Max(case when num=2 then Salary else null end) SecondHighestSalary
from (
select Salary,row_number() over(order by Salary desc) as num
from (select distinct Salary from Employee)a)b;
```