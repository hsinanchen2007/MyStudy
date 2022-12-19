### 解题思路
第一次数据库的题通过了,nice

### 代码

```mssql
/* Write your T-SQL query statement below */
select e1.Name Employee from Employee e1,Employee e2
where e1.ManagerId = e2.Id and e1.Salary>e2.Salary
```
当然还有种写法是连接
```
select e1.Name Employee from Employee e1 join Employee e2
on e1.ManagerId = e2.Id and e1.Salary>e2.Salary
```
我记得老师说from后面逻辑上说是做了笛卡尔积,不过加了where实际应该和join实现是一样的.