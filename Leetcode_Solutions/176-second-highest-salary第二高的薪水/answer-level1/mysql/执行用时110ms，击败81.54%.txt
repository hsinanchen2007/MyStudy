### 解题思路
1.首先缩小我们查找max(salary)的范围，将本来原有的max(salary)不纳在考虑范围内
salary not in (select max(salary) from Employee)
将这行代码作为我们查找max(salary)的附加where条件
2.然后直接查询max(salary)即可

### 代码

```mysql
# Write your MySQL query statement below
select max(salary) as SecondHighestSalary
from Employee 
where salary not in (select max(salary) from Employee);
```