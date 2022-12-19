# Write your MySQL query statement below
select q.Name as Department,p.Name as Employee ,p.Salary
from 
(select a.*,
case 
when @prevDepartment = a.DepartmentId and @prevSalary = a.Salary then @rk
when @prevDepartment = a.DepartmentId and @prevSalary := a.Salary then @rk:=@rk+ 1
when @prevDepartment := a.DepartmentId then @rk:=1
end  as rk
from (select * from Employee order by DepartmentId,Salary desc) a,
(select @prevSalary := null, @prevDepartment:=null , @rk := 0) as t) as p
inner join Department q on q.Id = p.DepartmentId
where p.rk in ('1','2','3');