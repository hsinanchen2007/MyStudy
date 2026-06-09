### 解题思路
开始直接用的排序，结果两个100，取100竟然显示错了，那就是相同的就算同一个排序

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select max(z.SALARY) as "SecondHighestSalary" from (
select t.salary as "SALARY",
dense_rank() over(order by Salary desc) as "PX"
from Employee t order by t.salary desc) z where z.PX=2
```