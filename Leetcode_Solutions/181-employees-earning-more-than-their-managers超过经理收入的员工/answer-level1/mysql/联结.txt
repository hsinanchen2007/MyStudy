### 解题思路
此处撰写解题思路
简单的联结 更快应该不用联结
### 代码

```mysql
# Write your MySQL query statement below
Select a.Name as Employee
From Employee a join Employee b
Where(a.ManagerId = b.Id
    and
     a.Salary>b.Salary)
;
```