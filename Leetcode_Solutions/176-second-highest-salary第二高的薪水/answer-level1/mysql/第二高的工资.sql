### 解题思路
第二高的工资， 也就是除去最高的工资的最高工资 
用子查询去掉最高的工资然后max返回最高的工资就时第二高的工资
### 代码

```mysql
# Write your MySQL query statement below
select max(Salary) SecondHighestSalary from Employee where Salary<(select max(Salary) from Employee)
```