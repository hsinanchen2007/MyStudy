### 解题思路
-- 第一种写法没有排除相等的情况。
-- select IFNULL((select Salary from Employee order by Salary DESC limit 1 offset 1),null) as SecondHighestSalary from Employee limit 1;

<!-- 使用max,选择不等于第一高的最高值为第二高。 -->

### 代码

```mysql
# Write your MySQL query statement below

SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary != (SELECT MAX(salary) FROM Employee)
```