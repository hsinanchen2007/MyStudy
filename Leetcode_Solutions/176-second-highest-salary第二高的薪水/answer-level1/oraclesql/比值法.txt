### 解题思路
刚开始想着用排序后用RowNum进行筛选1<RowNum<3,写完后发现略显复查，
用最大值进行比值更简单。
### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select max(Salary) SecondHighestSalary from 
Employee 
where Salary !=(select max(Salary) from Employee)
```