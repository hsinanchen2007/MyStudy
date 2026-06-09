### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select a.Name as 'Employee' from Employee as a inner join Employee as b on a.ManagerId=b.Id where a.Salary > b.Salary;
```