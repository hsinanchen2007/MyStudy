### 解题思路
两种方法
第一种，是在where条件中使用子查询
第二种，是联合两个表查询

### 代码

```mysql
-- select a.Name as Employee from Employee a where a.Salary>(select Salary from Employee where Id=a.ManagerId)
select a.Name as Employee from Employee a,Employee b where a.ManagerId=b.Id and a.Salary>b.Salary
```