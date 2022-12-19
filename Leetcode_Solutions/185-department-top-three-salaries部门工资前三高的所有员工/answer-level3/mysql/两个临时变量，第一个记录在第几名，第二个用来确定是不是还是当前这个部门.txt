
解题思路，首先对Employee salary降序排序，然后用临时变量记录每个的排名，  最后取每个部门的前三名，然后最后再来一个大循环排序



select Department,Employee,Salary from (

    select  t2.name as 'Department',t1.name as 'Employee',t3.Salary,t3.DepartmentId
    from 
    (
    select salary,DepartmentId,
    (case 
        when DepartmentId=@flag
        then @num:=@num+1
        when @flag:=DepartmentId
        then @num:=1
     end
    ) as num
    from (
    select  salary,DepartmentId  from Employee group by DepartmentId,salary  order by  DepartmentId asc,salary desc)
    t1,(select @num:=1,@flag:=NULL)r
        )t3  inner join Employee  t1 inner join Department t2
        on t3.salary=t1.salary and t3.DepartmentId=t1.DepartmentId  and t3.num <4
        and t1.DepartmentId =t2.id
    order by DepartmentId asc,Salary desc
) temp 