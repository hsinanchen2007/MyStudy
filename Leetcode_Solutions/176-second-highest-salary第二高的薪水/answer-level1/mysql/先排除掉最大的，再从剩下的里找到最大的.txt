### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select max(Salary) SecondHighestSalary from Employee where Salary != (select max(e.Salary) max from Employee e)
```