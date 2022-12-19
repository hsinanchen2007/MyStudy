### 解题思路
此处撰写解题思路

### 代码

```mssql
/* Write your T-SQL query statement below */

select max(Salary) as SecondHighestSalary from Employee 
where Salary<(select max(Salary) from Employee)
```