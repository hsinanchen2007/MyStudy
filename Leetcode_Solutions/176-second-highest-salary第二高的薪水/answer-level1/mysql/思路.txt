### 解题思路
薪资第二高的记录，首先先到将原表按照薪资降序排列，然后取第二条记录。即为薪资第二高的薪水
第一步：
select distinct salary from employee
order by salary desc limit 1,1;
第二步：
将其命名为SecondHighestSalary
select
(select distinct salary from employee
order by salary desc limit 1,1;) as SecondHighestSalary
第三步：
如果第二高的薪水不存在，则输出NULL
使用ifnull()函数
select
ifnull((select distinct salary from employee
order by salary desc limit 1,1),null) as SecondHighestSalary

### 代码

```mysql
# Write your MySQL query statement below
select
ifnull
((select distinct salary from employee
order by salary desc limit 1,1),null)
as SecondHighestSalary
```