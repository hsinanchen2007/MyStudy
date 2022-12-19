### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
Select a.Name as Employee
From Employee as a inner join Employee as b
on a.ManagerId=b.Id 
Where a.salary > b.salary


```