### 解题思路
先使用分页思想算出第二高值，然后解决null的问题

### 代码

```mysql
# Write your MySQL query statement below
select ifnull((select distinct Salary from Employee order by Salary desc limit 1,1),null) as SecondHighestSalary;
```