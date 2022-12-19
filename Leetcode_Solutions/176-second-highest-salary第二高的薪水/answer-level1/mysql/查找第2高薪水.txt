### 解题思路
此处撰写解题思路
查找第2高薪水<查找最高薪水的结果即可
### 代码

```mysql
# Write your MySQL query statement below
select max(Salary)SecondHighestSalary from Employee
where
Salary < (select max(Salary) from Employee);




```