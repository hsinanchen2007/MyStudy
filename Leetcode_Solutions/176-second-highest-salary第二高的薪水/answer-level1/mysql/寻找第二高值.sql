### 解题思路
思考1.第二高有2种方式可以找到
1. 倒序排列，去第二个
2. 从比最高的小的数据中取最大的那个

### 代码

```mysql
# Write your MySQL query statement below
# select IFNULL((select Distinct Salary from Employee order by Salary DESC limit 1,1),null) as SecondHighestSalary 
select max(salary) as SecondHighestSalary
from Employee 
where salary < (select max(salary) from Employee);
```