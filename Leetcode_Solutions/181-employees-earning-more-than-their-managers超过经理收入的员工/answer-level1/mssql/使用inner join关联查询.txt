 已知表数据中存在`managers`关联关系，使用` inner join` 进行关联，自动去除`ManagerId` 为`null `的数据。
再增加条件，`where emp.Salary > mgr.Salary` 即可得到结果

```
select emp.Name as  Employee from Employee emp 
inner join Employee mgr on emp.ManagerId = mgr.Id
where emp.Salary > mgr.Salary
```