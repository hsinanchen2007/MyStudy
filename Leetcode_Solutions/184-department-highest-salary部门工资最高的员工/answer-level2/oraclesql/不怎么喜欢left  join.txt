select c.name as Department,
b.name as Employee,
b.Salary          --row_number()over()
from (select a.*, dense_rank()over(partition by a.departmentid order by salary desc) rn
from Employee a) b, Department c
where b.rn < 2
and b.departmentid = c.id;