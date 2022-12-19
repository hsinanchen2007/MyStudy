```
SELECT e0.Name as Employee FROM Employee e0 right join Employee e1 on [e0].ManagerId=[e1].Id where e0.Salary>e1.Salary;
```
