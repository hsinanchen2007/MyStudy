select dd.Name  Department, zz.name Employee ,zz.Salary  Salary  from
(select  dense_rank() over(partition by DepartmentId order by salary desc) rn ,ee.* from Employee ee) zz,
Department dd
where
zz.DepartmentId = dd.Id 
and zz.rn<=3