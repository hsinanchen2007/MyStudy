select ntb.`Department`,ntb.`Employee`,ntb.`Salary` from 
(
select tb.`Department`,tb.Name as `Employee`,tb.Salary as `Salary`, 
@i:=if(@preid=tb.Id,if(@presalary=tb.Salary,@i,@i+1),1) as cnt,
@preid:=tb.Id as nowid,
@presalary:=tb.Salary as nowsalary
from 
(select d.Id,d.Name as `Department`,e.Name,e.Salary from department d
left join employee e on d.Id=e.DepartmentId
order by d.Id asc,e.Salary desc)tb,(select @preid:=0,@i:=0,@presalary:=0) t
)ntb
where ntb.`cnt` between 1 and 3
and ifnull(ntb.`Employee`,'')<>''