### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select max(salary)  SecondHighestSalary from Employee where salary not in(select max(salary) from Employee )
```
跟着别人的思路，去除第一大后的第一大值