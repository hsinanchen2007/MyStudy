1. where

```
select A.Name as Employee
from 
Employee as A,
Employee as B

where A.ManagerId = B.Id
and A.Salary > B.Salary
```


2. join on
```
select A.Name as Employee
from Employee as A 
join Employee as B

on A.ManagerId = B.id
and A.Salary > B.Salary
```
