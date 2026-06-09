三轮提交后，显示超过90%的用户  
代码奇丑无比，速度比较虚，还有待优化…………
```
with Highest as(
    Select [Employee].DepartmentId as DepartmentId,Max([Employee].Salary) as MaxSalary from [Employee] Group by [Employee].DepartmentId
)
select [Department].Name as Department,[Employee].Name as Employee,[Employee].Salary from [Employee] join [Department] on [Employee].DepartmentId=[Department].Id Join [Highest] on [Department].Id=[Highest].DepartmentId where [Employee].Salary=[Highest].MaxSalary order by [Employee].Id;
```

