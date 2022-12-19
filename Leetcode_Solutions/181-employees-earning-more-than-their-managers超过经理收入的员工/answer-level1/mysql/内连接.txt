内连接，mysql 275ms
```
SELECT a.Name AS `Employee` FROM employee a join employee b on a.ManagerId=b.Id and a.Salary > b.Salary;
```
