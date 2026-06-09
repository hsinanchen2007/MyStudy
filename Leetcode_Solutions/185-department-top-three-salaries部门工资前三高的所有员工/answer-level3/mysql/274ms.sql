select Name as Department,Employee,Salary from(
    select 
        t1.DepartmentId as DepartmentId,
        Name as Employee,
        t1.Salary as Salary
    from Employee t1 join( 
        select
            Salary,
            @i:=case when @DepartmentId=DepartmentId then @i+1 else 1 end as ranking,
            @DepartmentId:=DepartmentId as DepartmentId
        from
            (select 
                distinct Salary,DepartmentId
            from Employee
            order by DepartmentId,Salary desc) t1,(select @i:=0,@DepartmentId:=0) t2) t2
    on t1.Salary=t2.Salary and t1.DepartmentId=t2.DepartmentId
    where ranking<=3) t1
join Department t2
on t1.DepartmentId=t2.Id
order by Department,Salary desc
