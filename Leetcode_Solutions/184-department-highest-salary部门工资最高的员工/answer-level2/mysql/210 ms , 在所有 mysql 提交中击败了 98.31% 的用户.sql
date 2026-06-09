select b.Name as Department  ,a.Name as Employee,a.Salary from(
select * from Employee
where (Salary,DepartmentId)
 in(
    select max(Salary) as Salary ,DepartmentId
    from Employee
    group by
    DepartmentId
)
) a left join Department b
on a.DepartmentId=b.Id
where b.Id is not null

