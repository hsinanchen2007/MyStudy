### 解题思路
要记得数据有重复的情况，需要distinct去重
### 代码

```mysql
# Write your MySQL query statement below
select ifnull((select distinct Salary from Employee order by Salary desc limit 1 offset 1),
null) SecondHighestSalary
```